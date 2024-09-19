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
std::string StringCalculator::extractDelimiter(std::string& input) {
    std::string delimiter = ",";  // Default delimiter
    if (input.substr(0, 2) == "//") {
        size_t newlinePos = input.find('\n');
        if (newlinePos != std::string::npos) {
            std::string delimiterSection = input.substr(2, newlinePos - 2);
            if (delimiterSection.front() == '[' && delimiterSection.back() == ']') {
                delimiter = delimiterSection.substr(1, delimiterSection.size() - 2);
            } else {
                delimiter = delimiterSection;
            }
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

// Helper function to calculate the sum of numbers, ignoring numbers greater than 1000
int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

// Main add function with support for custom delimiters and ignoring numbers > 1000
int StringCalculator::add(const std::string& input) {
    std::string modifiedInput = input;
    std::string delimiter = extractDelimiter(modifiedInput);  // Extract and set custom delimiter

    if (modifiedInput.empty()) {
        return 0;
    }

    // Replace new lines with the custom delimiter
    std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', delimiter[0]);

    std::vector<int> numbers = splitAndConvert(modifiedInput, delimiter[0]);  // Parse input
    validateNegatives(numbers);  // Check for negative numbers
    return sumNumbers(numbers);  // Calculate and return the sum
}
