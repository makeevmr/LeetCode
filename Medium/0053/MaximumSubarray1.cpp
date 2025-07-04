/* Given an integer array nums, find the subarray with the largest sum, and return its sum.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: count prefix sum on each step, subarray_sum = pref1_sum - pref2_sum, so we compute
curr_pref_sum on each step and keep min_pref_sum from[0...i]
*/

#include <vector>

class Solution {
public:
    [[nodiscard]] static int maxSubArray(std::vector<int>& nums) {
        int min_pref_sum = 0;
        int curr_pref_sum = 0;
        int max_subarray_sum = nums[0];
        int nums_size = static_cast<int>(nums.size());
        for (int i = 0; i < nums_size; ++i) {
            curr_pref_sum += nums[i];
            max_subarray_sum = std::max(max_subarray_sum, curr_pref_sum - min_pref_sum);
            min_pref_sum = std::min(min_pref_sum, curr_pref_sum);
        }
        return max_subarray_sum;
    }
};
