#include "html_fetcher.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

HTMLFetcher::HTMLFetcher(const std::string &url) : url(url) {}

std::pair<bool, std::string>
HTMLFetcher::login(const std::string &target,
                   const std::map<std::string, std::string> &login_data) {
  std::string result;
  net::io_context io_ctx;

  tcp::resolver resolver(io_ctx);
  tcp::socket socket(io_ctx);

  /* Sync variant; would be more efficient with async I/O
  Sadly, asio:spawn is not available in 1.71, so keep it simple for now.
  */
  try {
    const auto &results = resolver.resolve(url, "80");
    net::connect(socket, results.begin(), results.end());

    http::request<http::string_body> req{http::verb::post, target, 11};
    /* TODO: use http::version instead of 11 (but only available since 1.75) */
    req.set(http::field::host, url);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::content_type, "application/x-www-form-urlencoded");

    /* TODO: use boost::url::params (but only available since 1.8x) */
    std::string sep = "";
    std::string body = "";
    for (auto &[param, value] : login_data) {
        body += sep + param + "=" + value;
        sep = "&";
    }
    
    req.body() = body;
    req.prepare_payload();

    http::write(socket, req);

    beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(socket, buffer, res);

    std::string result = beast::buffers_to_string(res.body().data());
    return {true, result};
  } catch (const std::exception &e) {
    return {false, e.what()};
  }
}