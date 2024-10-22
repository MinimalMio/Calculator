#ifndef SCRIPT_EXECUTOR_H
#define SCRIPT_EXECUTOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>

#include "atomicMass.hpp"

extern std::map<std::string, double> variables;

void handleLetCommand(const std::string &line);
void handleShowCommand(const std::string &varName);
void handleDelCommand(const std::string &varName);
void handleArCommand(const std::string &formula);
void handleRectCommand(double sideLength);
double evaluateExpression(std::istringstream &iss);
void error(const std::string &msg);

static void handleExecCommand(const std::string &filePath) {
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
            } else {
                iss.clear();
                iss.str(line);
                double result = evaluateExpression(iss);
                std::cout << result << std::endl;
            }
        } catch (std::exception &e) {
            error(e.what());
        }
    }
    file.close();
}

#endif
