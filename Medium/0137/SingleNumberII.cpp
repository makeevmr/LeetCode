/* Given an integer array nums where every element appears three times except
for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only
constant extra space. Time complexity: O(n) Additional memory complexity: O(1)
Idea: count how many one bits in each position if (counter % 3 != 0) then (ans
|= 1 << position)
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    int nums_size = static_cast<int>(nums.size());
    for (int bit = 0; bit < 32; ++bit) {
      int ones_counter = 0;
      for (int i = 0; i < nums_size; ++i) {
        if (static_cast<bool>(nums[i] & (1 << bit))) {
          ++ones_counter;
        }
      }
      if (ones_counter % 3 != 0) {
        ans |= 1 << bit;
      }
    }
    return ans;
  }
};
