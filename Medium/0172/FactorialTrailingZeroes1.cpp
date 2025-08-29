/* Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
Time complexity: O(log5(n))
Additional memory complexity: O(log5(n))
Idea: count 5 factors in n!
*/

class Solution {
public:
  [[nodiscard]] static int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};