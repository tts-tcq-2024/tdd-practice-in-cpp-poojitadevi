#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <algorithm>  // For std::copy_if
#include <regex>      // For replacing newlines

// Helper function to split the input string and return a list of numbers
std::vector<int> StringCalculator::splitAndConvert(const std::string& input) {
    std::string modifiedInput = input;

    // Replace all newline characters with commas to handle both delimiters
    std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', ',');

    std::vector<int> numbers;
    std::stringstream ss(modifiedInput);
    std::string token;

    // Split the string by commas and convert each token to an integer
    while (std::getline(ss, token, ',')) {
        if (!token.empty()) {  // Ensure no empty tokens are processed
            numbers.push_back(std::stoi(token));
        }
    }

    return numbers;
}

// Helper function to validate for negative numbers and throw exceptions if found
void StringCalculator::validateNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;

    // Use std::copy_if to collect all negative numbers
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });

    // Throw exception if there are negative numbers
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
