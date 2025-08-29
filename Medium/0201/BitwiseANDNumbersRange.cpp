/* Given two integers left and right that represent the range [left, right],
return the bitwise AND of all numbers in this range, inclusive. Time complexity:
O(1) Additional memory complexity: O(1) Idea:  0 0000   bit_0 = num % 2 > 0 1
0001   bit_1 = num % 4 > 1 2 0010   bit_2 = num % 8 > 3 3 0011   bit_3 = num %
16 > 7 4 0100 5 0101 6 0110 7 0111 8 1000 9 1001 10 1010 11 1011 12 1100 13 1101
      14 1110
      15 1111

*/

#include <cstdint>

class Solution {
public:
  [[nodiscard]] static int rangeBitwiseAnd(const int left, const int right) {
    const uint64_t range_len = static_cast<uint64_t>(right) - left + 1;
    int answer = 0;
    uint64_t curr_pow_2 = 2;
    uint64_t prev_pow_2 = 1;
    for (int bit_num = 0; bit_num < 31; ++bit_num) {
      if (const uint64_t deduction_class =
              static_cast<uint64_t>(left) % curr_pow_2;
          (deduction_class > (prev_pow_2 - 1)) &&
          (curr_pow_2 - deduction_class >= range_len)) {
        answer |= (1 << bit_num);
      }
      curr_pow_2 *= 2;
      prev_pow_2 *= 2;
    }
    return answer;
  }
};