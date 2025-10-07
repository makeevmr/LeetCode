#include <string>

class Solution {
public:
  [[nodiscard]] static bool canMakeSubsequence(const std::string& str1,
                                               const std::string& str2) {
    const std::size_t str1_size = str1.size();
    const std::size_t str2_size = str2.size();
    if (str1_size < str2_size) {
      return false;
    }
    std::size_t str2_ind = 0;
    for (std::size_t str1_ind = 0; str1_ind < str1_size; ++str1_ind) {
      const char shifted_char = (str1[str1_ind] - 'a' + 1) % 26 + 'a';
      if (str1[str1_ind] == str2[str2_ind] || shifted_char == str2[str2_ind]) {
        ++str2_ind;
      }
      if (str2_ind == str2_size) {
        return true;
      }
    }
    return false;
  }
};