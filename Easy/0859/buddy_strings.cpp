#include <string>

class Solution {
public:
  [[nodiscard]] static bool buddyStrings(const std::string& s,
                                         const std::string& goal) {
    const std::size_t s_size = s.size();
    if (s_size != goal.size()) {
      return false;
    }
    int symbol_freq[26] = {};
    bool is_contain_repeated = false;
    int i = -1;
    int j = -1;
    for (std::size_t ind = 0; ind < s_size; ++ind) {
      if (symbol_freq[s[ind] - 'a'] == 1) {
        is_contain_repeated = true;
      }
      ++symbol_freq[s[ind] - 'a'];
      if (s[ind] != goal[ind]) {
        if (j != -1) {
          return false;
        }
        if (i == -1) {
          i = ind;
        } else {
          j = ind;
        }
      }
    }
    if (i == -1) {
      return is_contain_repeated;
    }
    if (j == -1) {
      return false;
    }
    return s[i] == goal[j] && s[j] == goal[i];
  }
};