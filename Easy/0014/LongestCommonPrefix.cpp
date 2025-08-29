// Write a function to find the longest common prefix string amongst an array of
// strings. Time complexity: O(N * K), where N is number of strings, K is string
// length Additional memory complexity: O(1)

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  static std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    std::size_t strs_size = strs.size();
    int prefix_length = -1;
    bool is_common_prefix = true;
    while (is_common_prefix) {
      ++prefix_length;
      if (static_cast<std::size_t>(prefix_length) >= strs[0].size()) {
        break;
      }
      char new_common_symbol = strs[0][prefix_length];
      for (std::size_t i = 1; i < strs_size; ++i) {
        if ((static_cast<std::size_t>(prefix_length) >= strs[i].size()) ||
            (new_common_symbol != strs[i][prefix_length])) {
          is_common_prefix = false;
          break;
        }
      }
    }
    if (prefix_length == 0) {
      return "";
    }
    return strs[0].substr(0, prefix_length);
  }
};

int main() {
  // const std::vector<std::string> strs = {"flower", "flow", "flight"};
  const std::vector<std::string> strs = {"dog", "racecar", "car"};
  std::cout << Solution::longestCommonPrefix(strs) << '\n';
  return 0;
}