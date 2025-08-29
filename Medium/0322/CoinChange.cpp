/* You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that
amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
Time complexity: O(amount * coins_size)
Additional memory complexity: O(amount)
Idea: use dynamic programming approach (in ways[i] store minimum coins needed to
form number i)
*/

#include <vector>
#include <limits>

class Solution {
public:
  [[nodiscard]] static int coinChange(const std::vector<int>& coins,
                                      int amount) {
    constexpr int kMaxInt = std::numeric_limits<int>::max();
    std::vector<int> ways(amount + 1, kMaxInt);
    ways[0] = 0;
    for (int i = 1; i < amount + 1; ++i) {
      for (const auto& coin : coins) {
        if (i - coin >= 0 && ways[i - coin] != kMaxInt) {
          ways[i] = std::min(ways[i], ways[i - coin] + 1);
        }
      }
    }
    return ways.back() != kMaxInt ? ways.back() : -1;
  }
};
