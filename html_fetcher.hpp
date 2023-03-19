#pragma once

#include <string>
#include <map>

class HTMLFetcher {
public:
    HTMLFetcher(const std::string& url);
    std::pair<bool, std::string> login(const std::string& target, const std::map<std::string, std::string>& login_data) {
        std::string result = "result";
        return {true, result};
    }

private:
    std::string url;
};
