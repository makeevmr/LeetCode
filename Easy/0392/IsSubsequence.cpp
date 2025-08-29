#include <iostream>
#include <string>

class Solution {
public:
  static bool isSubsequence(const std::string& s, const std::string& t) {
    int left_str_index = 0;
    int left_str_size = static_cast<int>(s.size());
    int right_str_index = 0;
    int right_str_size = static_cast<int>(t.size());
    while ((left_str_index < left_str_size) &&
           (right_str_index < right_str_size)) {
      if (s[left_str_index] == t[right_str_index]) {
        ++left_str_index;
      }
      ++right_str_index;
    }
    if (left_str_index == left_str_size) {
      return true;
    }
    return false;
  }
};

int main() {
  std::string s = "abc";
  std::string t = "ahbgdc";
  std::cout << Solution::isSubsequence(s, t) << std::endl;
  return 0;
}
