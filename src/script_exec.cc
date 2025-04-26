#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>

#include "atomic_mass.h"
#include "basic_math.h"
#include "eval_comparison.h"
#include "message_lib.h"
#include "handlelib.h"

void handleExecCommand(const std::string filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        error("Could not open file: " + filePath);
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
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
            } else if (command == "rect") {
                double sideLength;
                iss >> sideLength;
                handleRectCommand(sideLength);
            } else if (command == "println") {
                std::string printChar;
                iss >> printChar;
                std::cout << printChar << std::endl;
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
    }
    file.close();
}