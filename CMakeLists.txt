cmake_minimum_required(VERSION 3.16)

project(cli_login)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(cli_login cli_login.cpp html_fetcher.cpp)
