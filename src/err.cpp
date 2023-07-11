#include "err.hpp"
#include <iostream>

bool err_hadError = false;

bool err::hadError() {
    return err_hadError;
}

void err::error(int line, std::string msg) {
    std::cout  << "\e[0;31m" << "Error | " << line << " : " << msg << "\033[0m" << std::endl;
    err_hadError = true;
}