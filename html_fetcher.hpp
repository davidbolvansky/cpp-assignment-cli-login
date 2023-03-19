#pragma once

#include <string>
#include <map>

#include <boost/asio.hpp>
#include <boost/beast.hpp>


class HTMLFetcher {
public:
  /**
   * @brief Constructs an HTMLFetcher object for the specified URL.
   * @param url A base URL for subsequent HTTP requests
   */
  HTMLFetcher(const std::string &url);
  /**
   * @brief Performs an HTTP POST request to log in to a given target URL with
   * the provided login data.
   * @param target A target URL to perform the login request
   * @param login_data A map containing the login data
   * @return A pair containing a boolean flag and string: true and the response
   * content as a string or false and an error message
   */
  std::pair<bool, std::string>
  login(const std::string &target,
        const std::map<std::string, std::string> &login_data);

private:
    std::string url;
};
