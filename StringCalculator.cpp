#include "StringCalculator.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <algorithm>

// Helper function to split the input string by a given delimiter
std::vector<int> StringCalculator::splitAndConvert(const std::string& input, char delimiter) {
    std::vector<int> numbers;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()) {
            numbers.push_back(std::stoi(token));
        }
    }

    return numbers;
}

// Helper function to extract the delimiter from the input string
char StringCalculator::extractDelimiter(std::string& input) {
    char delimiter = ',';  // Default delimiter
    if (input.substr(0, 2) == "//") {
        size_t newlinePos = input.find('\n');
        if (newlinePos != std::string::npos) {
            delimiter = input[2];
            input = input.substr(newlinePos + 1);  // Remove delimiter line from input
        }
    }
    return delimiter;
}

// Helper function to validate for negative numbers and throw exceptions if found
void StringCalculator::validateNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int number) {
        return number < 0;
    });

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

// Main add function with support for custom delimiters
int StringCalculator::add(const std::string& input) {
    std::string modifiedInput = input;
    char delimiter = extractDelimiter(modifiedInput);  // Extract and set custom delimiter

    if (modifiedInput.empty()) {
        return 0;
    }

    // Replace new lines with the custom delimiter
    std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', delimiter);

    std::vector<int> numbers = splitAndConvert(modifiedInput, delimiter);  // Parse input
    validateNegatives(numbers);  // Check for negative numbers
    return sumNumbers(numbers);  // Calculate and return the sum
}
