/* Given two binary strings a and b, return their sum as a binary string.
Time compexity: O(a_size + b_size)
Additional memory compexity: O(a_size + b_size)
Idea: use column addition
*/

#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
  [[nodiscard]] static std::string addBinary(const std::string& a,
                                             const std::string& b) {
    int a_size = static_cast<int>(a.size());
    int b_size = static_cast<int>(b.size());
    bool is_bit_overflow = false;
    std::string sum(std::max(a_size, b_size) + 1, '0');
    int s_size = static_cast<int>(sum.size());
    int a_ind = a_size - 1;
    int b_ind = b_size - 1;
    int sum_ind = s_size - 1;
    while (a_ind >= 0 && b_ind >= 0) {
      int digit_sum =
          a[a_ind] - '0' + b[b_ind] - '0' + static_cast<int>(is_bit_overflow);
      sum[sum_ind] = static_cast<char>(digit_sum % 2) + '0';
      is_bit_overflow = static_cast<bool>(digit_sum / 2);
      --a_ind;
      --b_ind;
      --sum_ind;
    }
    while (a_ind >= 0) {
      int digit_sum = a[a_ind] - '0' + static_cast<int>(is_bit_overflow);
      sum[sum_ind] = static_cast<char>(digit_sum % 2) + '0';
      is_bit_overflow = static_cast<bool>(digit_sum / 2);
      --a_ind;
      --sum_ind;
    }
    while (b_ind >= 0) {
      int digit_sum = b[b_ind] - '0' + static_cast<int>(is_bit_overflow);
      sum[sum_ind] = static_cast<char>(digit_sum % 2) + '0';
      is_bit_overflow = static_cast<bool>(digit_sum / 2);
      --b_ind;
      --sum_ind;
    }
    if (is_bit_overflow) {
      sum[sum_ind] = '1';
    }
    if (sum.front() == '0' && sum.size() > 1) {
      return sum.substr(1, sum.size() - 1);
    }
    return sum;
  }
};

int main() {
  // std::string a = "11";
  // std::string b = "1";
  std::string a = "1010";
  std::string b = "1011";
  std::cout << Solution::addBinary(a, b) << '\n';
  return 0;
}