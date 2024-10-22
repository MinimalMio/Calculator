#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <map>

extern std::map<std::string, double> variables;

void error(const std::string &msg);

double evaluateExpression(std::istringstream &iss);

double evaluateTerm(std::istringstream &iss);

double evaluatePower(std::istringstream &iss);

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
    double result = evaluatePower(iss);
    while (iss) {
        char op;
        iss >> op;
        if (op == '*' || op == '/') {
            double nextFactor = evaluatePower(iss);
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

double evaluatePower(std::istringstream &iss) {
    double result = evaluateFactor(iss);
    char op;
    iss >> op;
    if (op == '^') {
        double exponent = evaluatePower(iss);
        result = pow(result, exponent);
    } else {
        iss.putback(op);
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
        if (c != ')') throw std::runtime_error("Mismatched parentheses");
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

#endif