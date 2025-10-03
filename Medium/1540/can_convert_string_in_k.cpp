#include <array>
#include <string>
#include <cmath>

class Solution {
public:
  [[nodiscard]] bool canConvertString(const std::string& s,
                                      const std::string& t, int k) {
    const std::size_t s_size = s.size();
    const std::size_t t_size = t.size();
    if (s_size != t_size) {
      return false;
    }
    for (std::size_t i = 0; i < s_size; ++i) {
      int steps = std::abs(static_cast<int>(s[i] - t[i]));
      if (s[i] > t[i]) {
        steps = 26 - steps;
      }
      ++symbol_diffs_[steps];
    }
    int max_diff_num = 0;
    int max_diff_counter = 0;
    for (int i = 1; i <= 25; ++i) {
      if (max_diff_counter <= symbol_diffs_[i]) {
        max_diff_counter = symbol_diffs_[i];
        max_diff_num = i;
      }
    }
    if (max_diff_counter == 0) {
      return true;
    }
    int total_turns = (max_diff_counter - 1) * 26;
    total_turns += max_diff_num;
    return total_turns <= k;
  }

private:
  static constexpr int kAlphaSize = 26;
  std::array<int, kAlphaSize + 1> symbol_diffs_ = {0};
};