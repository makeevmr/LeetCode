/* Reverse bits of a given 32 bits unsigned integer.
Time complexity: O(bits_len)
Additional memory complexity: O(1)
Idea: swap each bit pair
*/

#include <cstdint>

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    for (int offset = 0; offset <= 15; ++offset) {
      bool left_bit = static_cast<bool>(n & (1 << (31 - offset)));
      bool right_bit = static_cast<bool>(n & (1 << offset));
      n &= ~(1 << (31 - offset));
      n &= ~(1 << offset);
      n |= static_cast<uint32_t>(left_bit) << offset;
      n |= static_cast<uint32_t>(right_bit) << (31 - offset);
    }
    return n;
  }
};
