#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& input);

private:
    // Helper function to split the input string by a given delimiter
    std::vector<int> splitAndConvert(const std::string& input, char delimiter);
    
    // Helper function to extract the delimiter from the input string
    std::string extractDelimiter(std::string& input);
    
    // Helper function to get the delimiter from the delimiter specification
    std::string getDelimiterFromSpec(const std::string& spec);

    // Helper function to validate for negative numbers and throw exceptions if found
    void validateNegatives(const std::vector<int>& numbers);
    
    // Helper function to calculate the sum of numbers, ignoring numbers greater than 1000
    int sumNumbers(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
