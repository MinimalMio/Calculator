#ifndef EVAL_COMPARISON
#define EVAL_COMPARISON

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "parse_operand.h"

inline std::string evaluateComparison(std::istringstream &iss) {
    std::string leftStr, rightStr;
    std::string op;
    iss >> leftStr >> op >> rightStr;

    double left = parseOperand(leftStr);
    double right = parseOperand(rightStr);

    if (op == "==") {
        return (left == right) ? "true" : "false";
    } else if (op == "<<") {
        return (left < right) ? "true" : "false";
    } else if (op == ">>") {
        return (left > right) ? "true" : "false";
    } else if (op == "<=") {
        return (left <= right) ? "true" : "false";
    } else if (op == ">=") {
        return (left >= right) ? "true" : "false";
    } else {
        throw std::runtime_error("Unknown comparison operator");
    }
}

#endif