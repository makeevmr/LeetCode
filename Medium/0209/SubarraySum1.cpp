#include <iostream>
#include <vector>

class Solution {
public:
  static int minSubArrayLen(int target, const std::vector<int>& nums) {
    int left_index = 0;
    int right_index = -1;
    size_t nums_size = nums.size();
    unsigned long long int current_sum = 0;
    while ((right_index + 1) < nums_size && current_sum < target) {
      ++right_index;
      current_sum += nums[right_index];
    }
    if (current_sum < target) {
      return 0;
    }
    if (right_index == left_index) {
      return 1;
    }
    int min_subarray_length = right_index - left_index + 1;
    while (right_index < nums_size) {
      while ((current_sum - nums[left_index]) >= target) {
        current_sum -= nums[left_index];
        ++left_index;
        --min_subarray_length;
      }
      ++right_index;
      if (right_index < nums_size) {
        current_sum += nums[right_index];
        current_sum -= nums[left_index];
      }
      ++left_index;
    }
    return min_subarray_length;
  }
};

int main() {
  int target = 11;
  std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << Solution::minSubArrayLen(target, nums);
  return 0;
}
