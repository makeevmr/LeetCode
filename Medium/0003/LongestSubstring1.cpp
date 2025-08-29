#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  static int lengthOfLongestSubstring(const std::string& s) {
    std::vector<int> symbols_index_array(256, -1);
    int s_size = s.size();
    int left_border = -1;
    int max_length = 0;
    for (int i = 0; i < s_size; ++i) {
      if (left_border < symbols_index_array[s[i]]) {
        left_border = symbols_index_array[s[i]];
      }
      symbols_index_array[s[i]] = i;
      if (max_length < i - left_border) {
        max_length = i - left_border;
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
