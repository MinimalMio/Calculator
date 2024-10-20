#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <cmath>

#include "include/calc.hpp"

std::map<std::string, double> variables;

void error(const std::string &msg) {
    std::cout << "[ERR] " << msg << std::endl;
}

double evaluateExpression(std::istringstream &iss);

double evaluateTerm(std::istringstream &iss);

double evaluateFactor(std::istringstream &iss);

double evaluateExpression(std::istringstream &iss) {
    double result = evaluateTerm(iss);
    while (iss) {
        char op;
        iss >> op;
        if (op == '+' || op == '-') {
            double nextTerm = evaluateTerm(iss);
            if (op == '+') result += nextTerm;
            else result -= nextTerm;
        } else {
            iss.putback(op);
            break;
        }
    }
    return result;
}

double evaluateTerm(std::istringstream &iss) {
    double result = evaluateFactor(iss);
    while (iss) {
        char op;
        iss >> op;
        if (op == '*' || op == '/') {
            double nextFactor = evaluateFactor(iss);
            if (op == '*') result *= nextFactor;
            else if (nextFactor == 0) throw std::runtime_error("Divider cannot be zero.");
            else result /= nextFactor;
        } else {
            iss.putback(op);
            break;
        }
    }
    return result;
}

double evaluateFactor(std::istringstream &iss) {
    double result;
    char c;
    iss >> c;
    if (c == '(') {
        result = evaluateExpression(iss);
        iss >> c;
    } else if (isalpha(c)) {
        std::string var;
        iss.putback(c);
        iss >> var;
        if (variables.find(var) != variables.end()) {
            result = variables[var];
        } else {
            throw std::runtime_error("Unknown variable: " + var);
        }
    } else {
        iss.putback(c);
        iss >> result;
    }
    return result;
}

void handleLetCommand(const std::string &line) {
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

void handleShowCommand(const std::string &varName) {
    if (variables.find(varName) != variables.end()) {
        std::cout << variables[varName] << std::endl;
    } else {
        error("Unknown variable: " + varName);
    }
}

void handleDelCommand(const std::string &varName) {
    if (variables.erase(varName) == 0) {
        error("Unknown variable: " + varName);
    }
}

void showHelp() {
    std::cout << "Calculator v" << version << std::endl;
    std::cout << "let : define a variable" << std::endl;
    std::cout << "show: print value of a variable" << std::endl;
    std::cout << "del : del a variable" << std::endl;
    std::cout << "help: show this message" << std::endl;
    std::cout << "ver : display version" << std::endl;
    std::cout << "exit: exit\n";
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
            } else if (command == "help") {
                showHelp();
            } else if (command == "ver") {
                showVersion();
            } else if (command == "exit") {
                break;
            } else {
                iss.clear();
                iss.str(line);
                double result = evaluateExpression(iss);
                std::cout << result << std::endl;
            }
        } catch (std::exception &e) {
            error(e.what());
        }
        std::cout << ">>> ";
    }
    return 0;
}
