#ifndef SCRIPT_EXECUTOR_H
#define SCRIPT_EXECUTOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>

extern void handleLetCommand(const std::string line);
extern void handleShowCommand(const std::string varName);
extern void handleDelCommand(const std::string varName);
extern void handleArCommand(const std::string formula);
extern void handleRectCommand(double sideLength);
extern double evaluateExpression(std::istringstream iss);
extern void handleExecCommand(const std::string filePath);

#endif
