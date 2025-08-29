/* Given a circular integer array nums of length n, return the maximum possible
sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the
array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the
previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once.
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not
exist i <= k1, k2 <= j with k1 % n == k2 % n. Time complexity: O(n) Additional
memory complexity: O(1) Idea: if max_subarray inside nums than answer is
MaxKadane(nums) algorithm, if max_sum in nums edges than answer is total_sum -
MinKadane(nums)
*/

#include <iostream>
#include <vector>

class Solution {
public:
  [[nodiscard]] static int maxSubarraySumCircular(
      const std::vector<int>& nums) {
    bool is_all_neg = true;
    int total_sum = getTotalSum(nums, is_all_neg);
    if (is_all_neg) {
      return maxKadane(nums);
    }
    return std::max(maxKadane(nums), total_sum - minKadane(nums));
  }

private:
  [[nodiscard]] static int maxKadane(const std::vector<int>& nums) {
    int max_sum = nums[0];
    int curr_sum = 0;
    int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size; ++i) {
      curr_sum += nums[i];
      max_sum = std::max(max_sum, curr_sum);
      if (curr_sum < 0) {
        curr_sum = 0;
      }
    }
    return max_sum;
  }

  [[nodiscard]] static int minKadane(const std::vector<int>& nums) {
    int min_sum = nums[0];
    int curr_sum = 0;
    int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size; ++i) {
      curr_sum += nums[i];
      min_sum = std::min(min_sum, curr_sum);
      if (curr_sum > 0) {
        curr_sum = 0;
      }
    }
    return min_sum;
  }

  [[nodiscard]] static int getTotalSum(const std::vector<int>& nums,
                                       bool& is_all_neg) {
    int total_sum = 0;
    for (const auto& num : nums) {
      total_sum += num;
      if (num >= 0) {
        is_all_neg = false;
      }
    }
    return total_sum;
  }
};
