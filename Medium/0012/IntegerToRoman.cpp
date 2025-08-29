// Convert given integer value to Roman, 1 <= num <= 3999

#include <cmath>
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  static std::string intToRoman(int num) {
    const std::map<int, char> roman_symbols = {
        {1, 'I'},   {5, 'V'},   {10, 'X'},  {50, 'L'},
        {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    const std::map<int, std::string> subtractive_forms = {
        {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
    std::string roman_num;
    while (num > 0) {
      std::pair<int, int> front_digit = getFrontDigit(num);
      if (front_digit.first == 4 || front_digit.first == 9) {
        int subtracted_number =
            front_digit.first * std::pow(10, front_digit.second - 1);
        roman_num += subtractive_forms.at(subtracted_number);
        num -= subtracted_number;
      } else {
        std::map<int, char>::const_iterator ub_iter =
            roman_symbols.upper_bound(num);
        --ub_iter;
        roman_num += ub_iter->second;
        num -= ub_iter->first;
      }
    }
    return roman_num;
  }

private:
  static std::pair<int, int> getFrontDigit(int number) {
    int digits = 4;
    int divider = 1000;
    while ((number / divider) == 0) {
      divider /= 10;
      --digits;
    }
    return {number / divider, digits};
  }
};

int main() {
  int num = 0;
  std::cin >> num;
  std::cout << Solution::intToRoman(num) << '\n';
  return 0;
}
