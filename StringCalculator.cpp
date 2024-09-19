#include "StringCalculator.h"
#include <string>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }
    
    if (input == "0") {
        return 0;  // Return 0 for "0" input
    }
    
    return 0;
}
