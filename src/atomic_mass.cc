#include <string>

#include "atomic_mass.h"

void handleArCommand(const std::string element) {
    auto it = atomicMass.find(element);
    if (it != atomicMass.end()) {
        std::cout << it->second << std::endl;
    } else {
        throw std::runtime_error("Unknown element: " + element);
    }
}

void handleMrCommand(const std::string formula) {
    double totalMass = 0;
    std::string element;
    int count = 0;

    for (size_t i = 0; i < formula.length(); ++i) {
        if (isupper(formula[i])) {
            if (!element.empty()) {
                if (atomicMass.find(element) == atomicMass.end()) {
                    throw std::runtime_error("Unknown element: " + element);
                }
                totalMass += atomicMass[element] * (count == 0 ? 1 : count);
            }
            element = formula[i];
            count = 0;
        } else if (islower(formula[i])) {
            element += formula[i];
        } else if (isdigit(formula[i])) {
            count = count * 10 + (formula[i] - '0');
        }

        if (i == formula.length() - 1 && !element.empty()) {
            if (atomicMass.find(element) == atomicMass.end()) {
                throw std::runtime_error("Unknown element: " + element);
            }
            totalMass += atomicMass[element] * (count == 0 ? 1 : count);
        }
    }

    std::cout << totalMass << std::endl;
}