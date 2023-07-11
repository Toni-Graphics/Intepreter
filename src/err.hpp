#pragma once

#include <string>

namespace err {
    bool hadError();
    void error(int line, std::string msg);
}