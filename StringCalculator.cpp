#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <numeric>

// Helper function to split the input string and return a list of numbers
std::vector<int> StringCalculator::splitAndConvert(const std::string& input) {
    std::vector<int> numbers;
    std::stringstream ss(input);
    std::string token;
    
    while (std::getline(ss, token, ',')) {
        numbers.push_back(std::stoi(token));
    }
    
    return numbers;
}

// Helper function to validate for negative numbers and throw exceptions if found
void StringCalculator::validateNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;

    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }

    if (!negatives.empty()) {
        std::string errorMessage = "Negatives not allowed: ";
        for (int n : negatives) {
            errorMessage += std::to_string(n) + " ";
        }
        throw std::runtime_error(errorMessage);
    }
}

// Helper function to calculate the sum of numbers
int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

// Main add function with CCN of 1
int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::vector<int> numbers = splitAndConvert(input);  // Parse input
    validateNegatives(numbers);  // Check for negative numbers
    return sumNumbers(numbers);  // Calculate and return the sum
}
