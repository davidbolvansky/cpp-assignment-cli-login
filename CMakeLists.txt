cmake_minimum_required(VERSION 3.16)

project(cli_login)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system thread)
add_executable(cli_login cli_login.cpp html_fetcher.cpp)
target_link_libraries(cli_login ${Boost_LIBRARIES})

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_cli_login test_cli_login.cpp html_fetcher.cpp)
target_link_libraries(test_cli_login ${Boost_LIBRARIES} gtest gtest_main)
add_test(NAME test_cli_login COMMAND test_cli_login)