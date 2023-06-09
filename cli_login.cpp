#include "html_fetcher.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  HTMLFetcher fetcher{"testphp.vulnweb.com"};
  std::map<std::string, std::string> login_data;
  login_data["uname"] = "test";
  login_data["pass"] = "test";
  auto [success, result] = fetcher.login("/userinfo.php", login_data);
  if (!success) {
    std::cerr << result << std::endl;
    return 1;
  }

  std::cout << result << std::endl;
  return 0;
}
