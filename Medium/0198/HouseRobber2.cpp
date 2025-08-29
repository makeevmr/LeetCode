/* You are a professional robber planning to rob houses along a street. Each
house has a certain amount of money stashed, the only constraint stopping you
from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the
police. Time complexity: O(n) Additional memory complexity: O(1) Idea:  dynamic
programming (max value we can get robbing bank in current position and some prev
banks)
*/

#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int rob(std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    if (nums_size == 1) {
      return nums[0];
    }
    if (nums_size == 2) {
      return std::max(nums[0], nums[1]);
    }
    int val0 = nums[0];
    int val1 = nums[1];
    int val2 = nums[2] + val0;
    for (int i = 3; i < nums_size; ++i) {
      int new_val = nums[i] + std::max(val0, val1);
      val0 = val1;
      val1 = val2;
      val2 = new_val;
    }
    return std::max(val1, val2);
  }
};