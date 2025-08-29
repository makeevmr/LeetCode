/* You are given a large integer represented as an integer array digits, where
each digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
Time complexity: O(digits_size)
Additional memory complexity: O(digits_size)
Idea: use column_addition
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static std::vector<int> plusOne(
      const std::vector<int>& digits) {
    int digits_size = static_cast<int>(digits.size());
    int digits_ind = digits_size - 1;
    while (digits_ind >= 0 && digits[digits_ind] == 9) {
      --digits_ind;
    }
    std::vector<int> answer;
    if (digits_ind >= 0) {
      answer.resize(digits_size);
    } else {
      answer.resize(digits_size + 1);
    }
    int is_overflow = 1;
    for (int i = digits_size - 1; i >= 0; --i) {
      int new_num = digits[i] + is_overflow;
      answer[i] = new_num % 10;
      is_overflow = new_num / 10;
    }
    if (is_overflow == 1) {
      answer.front() = 1;
    }
    return answer;
  }
};