#include "html_fetcher.hpp"

#include <gtest/gtest.h>
#include <string>

TEST(LoginTest, NoLoginData) {
  HTMLFetcher fetcher{"testphp.vulnweb.com"};
  std::map<std::string, std::string> login_data;
  auto [success, result] = fetcher.login("/userinfo.php", login_data);

  ASSERT_TRUE(result.find("you must login") != std::string::npos);
}

TEST(LoginTest, CorrectLoginData) {
  HTMLFetcher fetcher{"testphp.vulnweb.com"};
  std::map<std::string, std::string> login_data;
  login_data["uname"] = "test";
  login_data["pass"] = "test";
  auto [success, result] = fetcher.login("/userinfo.php", login_data);

  ASSERT_TRUE(success);
  ASSERT_TRUE(result.find("Logout test") != std::string::npos);
}

TEST(LoginTest, IncorrectLoginData) {
  HTMLFetcher fetcher{"testphp.vulnweb.com"};
  std::map<std::string, std::string> login_data;
  login_data["uname"] = "test";
  login_data["pass"] = "tttt";
  auto [success, result] = fetcher.login("/userinfo.php", login_data);

  ASSERT_TRUE(success);
  ASSERT_TRUE(result.find("you must login") != std::string::npos);
}

TEST(LoginTest, BadHost) {
  HTMLFetcher fetcher{"testphp.vulnweb.ccc"};
  std::map<std::string, std::string> login_data;
  login_data["uname"] = "test";
  login_data["pass"] = "test";
  auto [success, result] = fetcher.login("/userinfo.php", login_data);

  ASSERT_FALSE(success);
  ASSERT_TRUE(result.find("Host not found") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}