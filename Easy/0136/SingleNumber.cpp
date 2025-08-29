/* Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space. Time complexity: O(nums_size) Additional memory
complexity: O(1) Idea: use bitwise addition (xor operation)
*/

#include <iostream>
#include <vector>

class Solution {
public:
  [[nodiscard]] static int singleNumber(const std::vector<int>& nums) {
    int answer = 0;
    for (int i = 0, nums_size = static_cast<int>(nums.size()); i < nums_size;
         ++i) {
      answer ^= nums[i];
    }
    return answer;
  }
};
