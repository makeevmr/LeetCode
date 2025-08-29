/* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top? Time complexity: O(n) Additional memory complexity: O(n) Idea:
use dynamic programming approach (dp_ways[i] contains how many ways to arrive on
step i + 1)
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int climbStairs(int n) {
    std::vector<int> dp_ways(n, 0);
    dp_ways[0] = 1;
    if (n > 1) {
      dp_ways[1] = 2;
    }
    for (int i = 2; i < n; ++i) {
      dp_ways[i] = dp_ways[i - 1] + dp_ways[i - 2];
    }
    return dp_ways.back();
  }
};
