# cpp-assignment-cli-login

# Description
This open source console program simulates login to http://testphp.vulnweb.com/login.php - sends login form data to http://testphp.vulnweb.com/userinfo.php - and displays the returned HTML page.

# Requirements
C++17 compiler (GCC 9.1+ / Clang 6.0+)  
Boost 1.71+ (Boost Beast for HTTP communication)  
gtest 1.10+ (for unit tests)  

Tested on Ubuntu 20.04 with gcc 9.4 and boost 1.71.  

# Build steps
mkdir build  
cd build  
cmake ../  
make  

# Run program
Run ./cli_login

# Run tests
In build dir run:  
ctest .  

or

./test_cli_login