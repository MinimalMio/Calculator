#ifndef PARSE_OPERAND
#define PARSE_OPERAND

#include <map>
#include <string>

extern std::map<std::string, double> variables;

inline double parseOperand(const std::string &operand) {
    if (variables.find(operand) != variables.end()) {
        return variables[operand];
    } else {
        return std::stod(operand);
    }
}

#endif