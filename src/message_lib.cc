#include <string>
#include <iostream>

#include "message_lib.h"

void error(const std::string &msg) {
    std::cout << "[ERR] " << msg << std::endl;
}