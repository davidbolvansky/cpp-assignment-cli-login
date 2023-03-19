#pragma once

#include <string>
#include <map>

#include <boost/asio.hpp>
#include <boost/beast.hpp>


class HTMLFetcher {
public:
    HTMLFetcher(const std::string& url);
    std::pair<bool, std::string> login(const std::string& target, const std::map<std::string, std::string>& login_data);

private:
    std::string url;
};
