#ifndef CALCULATOR_HANDLE_LIB
#define CALCULATOR_HANDLE_LIB

#include <string>

extern void handleLetCommand(const std::string line);
extern void handleShowCommand(const std::string varName);
extern void handleDelCommand(const std::string varName);
extern void handleRectCommand(double sideLength);

#endif