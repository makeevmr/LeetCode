/* Given an integer n, return the least number of perfect square numbers that
sum to n.


A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are
perfect squares while 3 and 11 are not. */

#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int numSquares(const int& n) {
    std::vector<int> squares;
    for (int i = 1; i * i <= n; ++i) {
      squares.push_back(i * i);
    }
    std::vector<int> num_squares(n + 1, std::numeric_limits<int>::max());
    num_squares[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (const int& square : squares) {
        if (i + square > n) {
          break;
        }
        num_squares[i + square] =
            std::min(num_squares[i + square], num_squares[i] + 1);
      }
    }
    return num_squares.back();
  }
};
