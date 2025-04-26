#include <string>
#include <sstream>

#include "message_lib.h"
#include "basic_math.h"
#include "calculator.h"

void handleLetCommand(const std::string line) {
    std::istringstream iss(line);
    std::string command, varName, equalSign;
    iss >> command >> varName >> equalSign;
    if (equalSign != "=") {
        error("Invalid let syntax");
        return;
    }
    double value = evaluateExpression(iss);
    variables[varName] = value;
}

void handleShowCommand(const std::string varName) {
    if (variables.find(varName) != variables.end()) {
        std::cout << variables[varName] << std::endl;
    } else {
        error("Unknown variable: " + varName);
    }
}

void handleDelCommand(const std::string varName) {
    if (variables.erase(varName) == 0) {
        error("Unknown variable: " + varName);
    }
}

void handleRectCommand(double sideLength) {
    double diagonal = sqrt(2) * sideLength;
    std::cout << diagonal << std::endl;
}