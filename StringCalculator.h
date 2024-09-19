#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& input);

private:
    std::vector<int> splitAndConvert(const std::string& input);
    void validateNegatives(const std::vector<int>& numbers);
    int sumNumbers(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
