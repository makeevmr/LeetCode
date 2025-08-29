/* Given an integer array nums, find the subarray with the largest sum, and
return its sum. Time complexity: O(n) Additional memory complexity: O(1) Idea:
use Kadane's algorithm
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int maxSubArray(std::vector<int>& nums) {
    int curr_subarray_sum = 0;
    int max_subarray_sum = nums[0];
    int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size; ++i) {
      curr_subarray_sum += nums[i];
      max_subarray_sum = std::max(max_subarray_sum, curr_subarray_sum);
      if (curr_subarray_sum < 0) {
        curr_subarray_sum = 0;
      }
    }
    return max_subarray_sum;
  }
};