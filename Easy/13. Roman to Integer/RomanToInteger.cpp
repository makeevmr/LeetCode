#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

class Solution {
public:
    static int romanToInt(const std::string &s) {
        std::unordered_map<char, int> roman_map = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                                   {'C', 100}, {'D', 500}, {'M', 1000}};
        int number = roman_map[s.back()];
        char prev_char = s.back();
        for (auto b_iter = ++s.rbegin(); b_iter != s.rend(); ++b_iter) {
            if (roman_map[prev_char] > roman_map[*b_iter]) {
                number -= roman_map[*b_iter];
            } else {
                number += roman_map[*b_iter];
            }
            prev_char = *b_iter;
        }
        return number;
    }
};

int main() {
    std::string s;
    std::cin >> s;
    std::cout << Solution::romanToInt(s) << '\n';
    return 0;
}