#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;  // Return 0 for empty input
    }

    std::stringstream ss(input);
    std::string token;
    int sum = 0;
    std::vector<int> negatives;

    // Split the string by commas and handle numbers
    while (std::getline(ss, token, ',')) {
        int number = std::stoi(token);  // Convert the token to an integer

        if (number < 0) {
            negatives.push_back(number);  // Track negative numbers
        }

        sum += number;  // Add the number to the sum
    }

    // If any negative numbers were found, throw an exception
    if (!negatives.empty()) {
        std::string errorMessage = "Negatives not allowed: ";
        for (int n : negatives) {
            errorMessage += std::to_string(n) + " ";
        }
        throw std::runtime_error(errorMessage);
    }

    return sum;
}
