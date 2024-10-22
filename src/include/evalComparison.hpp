#ifndef EVAL_COMPARISON
#define EVAL_COMPARISON

#include <iostream>
#include <string>
#include <sstream>

inline std::string evaluateComparison(std::istringstream &iss) {
    double left, right;
    std::string op;
    iss >> left >> op >> right;

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