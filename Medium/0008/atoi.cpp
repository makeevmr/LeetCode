#include <cctype>
#include <string>
#include <cstdint>
#include <cctype>

#include <iostream>

class Solution {
public:
  [[nodiscard]] static int myAtoi(const std::string& s) {
    const std::size_t s_size = s.size();
    std::size_t s_ind = 0;
    bool is_positive = true;
    std::int64_t answer = 0;
    while ((s_ind < s_size) && (s[s_ind] == ' ')) {
      ++s_ind;
    }
    if ((s_ind < s_size) && (s[s_ind] == '+' || s[s_ind] == '-')) {
      is_positive = (s[s_ind] == '+');
      ++s_ind;
    }
    while ((s_ind < s_size) && (s[s_ind] == '0')) {
      ++s_ind;
    }
    while ((s_ind < s_size) && (std::isdigit(s[s_ind]) != 0)) {
      answer = answer * 10 + static_cast<std::int64_t>(s[s_ind] - '0');
      if (!is_positive && answer >= kMinVal) {
        return static_cast<int>(-kMinVal);
      }
      if (is_positive && answer >= kMaxVal) {
        return static_cast<int>(kMaxVal);
      }
      ++s_ind;
    }
    if (!is_positive) {
      answer *= -1;
    }
    return static_cast<int>(answer);
  }

private:
  static constexpr std::int64_t kMinVal = 2147483648;
  static constexpr std::int64_t kMaxVal = 2147483647;
};

int main() {
  std::string s = "   -042";
  std::cout << Solution::myAtoi(s) << '\n';
  return 0;
}