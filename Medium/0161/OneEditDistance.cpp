/* Given two strings s and t, determine if they are both one edit distance
apart.

Note:

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Time complexity: O(s_size)
Additional memory complexity: O(1)
Idea: use two pointers (for s and t strings) to compare symbols
*/

#include <cmath>
#include <iostream>
#include <string>

class Solution {
public:
  [[nodiscard]] static bool isOneEditDistance(const std::string& s,
                                              const std::string& t) {
    int s_size = static_cast<int>(s.size());
    int t_size = static_cast<int>(t.size());
    if (std::abs(s_size - t_size) > 1) {
      return false;
    }
    int s_ind = 0;
    int t_ind = 0;
    int diff_counter = 0;
    while (s_ind < s_size && t_ind < t_size) {
      if (s[s_ind] == t[t_ind]) {
        ++s_ind;
        ++t_ind;
      } else {
        ++diff_counter;
        if (diff_counter > 1) {
          return false;
        }
        if (s_size == t_size) {
          ++s_ind;
          ++t_ind;
        } else if (s_size > t_size) {
          ++s_size;
        } else {
          ++t_ind;
        }
      }
    }
    return diff_counter == 1;
  }
};

int main() {
  // std::string s = "ab";
  // std::string t = "acb";
  // std::string s = "cab";
  // std::string t = "ad";
  std::string s = "1203";
  std::string t = "1213";
  std::cout << Solution::isOneEditDistance(s, t) << '\n';
  return 0;
}
