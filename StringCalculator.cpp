#include "StringCalculator.h"
#include <string>
#include <sstream>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    std::stringstream ss(input);
    std::string token;
    int sum = 0;

    // Split the string by commas
    while (std::getline(ss, token, ',')) {
        sum += std::stoi(token);  // Convert the string to an integer and add it to the sum
    }

    return sum;
}
