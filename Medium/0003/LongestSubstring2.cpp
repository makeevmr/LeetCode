#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  static int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<unsigned char, int> characters_map;
    std::unordered_map<unsigned char, int>::iterator e_iter =
        characters_map.end();
    int left_border = 0;
    int right_border = -1;
    int max_length = 0;
    for (unsigned char symbol : s) {
      ++right_border;
      std::unordered_map<unsigned char, int>::iterator f_iter =
          characters_map.find(symbol);
      if (f_iter == e_iter) {
        characters_map.insert({symbol, right_border});
      } else {
        if (left_border <= f_iter->second) {
          left_border = f_iter->second + 1;
        }
        f_iter->second = right_border;
      }
      if (max_length < (right_border - left_border + 1)) {
        max_length = right_border - left_border + 1;
      }
    }
    return max_length;
  }
};

int main() {
  std::string input_str;
  std::cin >> input_str;
  std::cout << Solution::lengthOfLongestSubstring(input_str) << std::endl;
  return 0;
}