/* Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Time complexity: O(log(n))
Additional memeory complexity: O(1)
Idea: use binary exponentiation
*/

#include <cmath>

class Solution {
public:
  [[nodiscard]] static double myPow(double x, int n) {
    bool is_pos_pow = n > 0;
    int pos_pow = std::abs(n);
    double answer = 1.0;
    while (pos_pow > 0) {
      if (static_cast<bool>(pos_pow & 1)) {
        answer *= x;
      }
      pos_pow >>= 1;
      x *= x;
    }
    return is_pos_pow ? answer : 1.0 / answer;
  }
};
