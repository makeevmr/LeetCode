/* Given a non-negative integer x, return the square root of x rounded down to
the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Time complexity: O(log(n))
Additional memory complexity: O(1)
Idea: use binary search
*/

#include <iostream>
#include <limits>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static int mySqrt(int x) {
    uint64_t arg = static_cast<uint64_t>(x);
    uint64_t left = 0;
    uint64_t right = static_cast<uint64_t>(std::numeric_limits<int>::max());
    while (left < right - 1) {
      uint64_t middle = (left + right) >> 1;
      uint64_t pow_2 = middle * middle;
      if (pow_2 > arg) {
        right = middle;
      } else {
        left = middle;
      }
    }
    return static_cast<int>(left);
  }
};