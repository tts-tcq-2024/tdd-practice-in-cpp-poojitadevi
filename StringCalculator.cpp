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

// Helper function to get the delimiter from the delimiter specification
std::string StringCalculator::getDelimiterFromSpec(const std::string& spec) {
    if (spec.front() == '[' && spec.back() == ']') {
        return spec.substr(1, spec.size() - 2); // Extract delimiter from [delimiter]
    }
    return spec; // Return the delimiter as is
}

// Helper function to extract the delimiter from the input string
std::string StringCalculator::extractDelimiter(std::string& input) {
    if (input.substr(0, 2) != "//") {
        return ","; // Default delimiter
    }

    size_t newlinePos = input.find('\n');
    if (newlinePos == std::string::npos) {
        return ","; // Default delimiter if no newline
    }

    std::string delimiterSpec = input.substr(2, newlinePos - 2);
    std::string delimiter = getDelimiterFromSpec(delimiterSpec);

    input = input.substr(newlinePos + 1); // Remove the delimiter specification line from input
    return delimiter;
}

// Helper function to validate for negative numbers and throw exceptions if found
void StringCalculator::validateNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;

    std::copy_if(numbers.begin(),
