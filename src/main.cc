#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>
#include <cmath>

#include "version.h"
#include "atomic_mass.h"
#include "script_exec.h"
#include "basic_math.h"
#include "eval_comparison.h"
#include "message_lib.h"
#include "calculator.h"

void showHelp() {
    std::cout << "Calculator v" << version  << std::endl;
    std::cout << "let   : define a variable" << std::endl;
    std::cout << "show  : print value of a variable" << std::endl;
    std::cout << "del   : del a variable" << std::endl;
    std::cout << "ar    : calculate relative atomic mass" << std::endl;
    std::cout << "mr    : calculate relative molecular mass" << std::endl;
    std::cout << "rect  : calculate the diagonal of a square" << std::endl;
    std::cout << "exec  : execute a script" << std::endl;
    std::cout << "help  : show this message" << std::endl;
    std::cout << "ver   : show version" << std::endl;
    std::cout << "exit  : exit" << std::endl;
}

void showVersion() {
    std::cout << "Calculator v" << version << std::endl;
}

int main() {
    std::cout << "Calculator v" << version << std::endl;
    std::string line;
    std::cout << ">>> ";
    while (std::getline(std::cin, line)) {
        try {
            std::istringstream iss(line);
            std::string command;
            iss >> command;
            if (command == "let") {
                handleLetCommand(line);
            } else if (command == "show") {
                std::string varName;
                iss >> varName;
                handleShowCommand(varName);
            } else if (command == "del") {
                std::string varName;
                iss >> varName;
                handleDelCommand(varName);
            } else if (command == "ar") {
                std::string formula;
                iss >> formula;
                handleArCommand(formula);
            } else if (command == "mr") {
                std::string formula;
                iss >> formula;
                handleMrCommand(formula);
            } else if (command == "rect") {
                double sideLength;
                iss >> sideLength;
                handleRectCommand(sideLength);
            } else if (command == "exec") {
                std::string filePath;
                iss >> filePath;
                handleExecCommand(filePath);
            } else if (command == "help") {
                showHelp();
            } else if (command == "ver") {
                showVersion();
            } else if (command == "exit") {
                break;
            } else {
                if (line.find("==") != std::string::npos ||
                    line.find("<<") != std::string::npos ||
                    line.find(">>") != std::string::npos ||
                    line.find("<=") != std::string::npos ||
                    line.find(">=") != std::string::npos) {
                    iss.clear();
                    iss.str(line);
                    std::string result = evaluateComparison(iss);
                    std::cout << result << std::endl;
                } else {
                    iss.clear();
                    iss.str(line);
                    double result = evaluateExpression(iss);
                    std::cout << result << std::endl;
                }
            }
        } catch (std::exception &e) {
            error(e.what());
        }
        std::cout << ">>> ";
    }
    return 0;
}
