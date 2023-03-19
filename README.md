# cpp-assignment-cli-login

# Description
This open source console program simulates login to http://testphp.vulnweb.com/login.php - sends login form data to http://testphp.vulnweb.com/userinfo.php - and displays the returned HTML page.

# Requirements
C++17 compiler
Boost (Boost Beast for HTTP communication)
gtest (for unit tests)

# Build steps
mkdir build
cd build
cmake ../
make

# Run steps
Run ./cli_login
