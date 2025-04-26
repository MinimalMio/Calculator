#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <map>

#include "message_lib.h"

extern double evaluateExpression(std::istringstream &iss);
extern double evaluateTerm(std::istringstream iss);
extern double evaluatePower(std::istringstream iss);
extern double evaluateFactor(std::istringstream iss);

#endif