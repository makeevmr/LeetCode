#include <iostream>
#include <vector>

class Solution {
public:
  static int minSubArrayLen(int target, const std::vector<int>& nums) {
    size_t nums_size = nums.size();
    unsigned long long int current_sum = 0;
    std::vector<unsigned long long int> prefix_sum;
    int min_length = 0;
    for (size_t i = 0; i < nums_size; ++i) {
      current_sum += nums[i];
      if (min_length == 0 && current_sum >= target) {
        min_length = i + 1;
      }
      prefix_sum.push_back(current_sum);
    }
    if (min_length <= 1) {
      return min_length;
    }
    if (min_length == nums_size && (current_sum - nums[0]) >= target) {
      --min_length;
    }
    for (int i = min_length; i < nums_size; ++i) {
      int current_index = i - min_length + 1;
      while (min_length > 1 &&
             (prefix_sum[i] - prefix_sum[current_index]) >= target) {
        ++current_index;
        --min_length;
      }
      if (min_length == 1) {
        break;
      }
    }
    return min_length;
  }
};

int main() {
  int target = 11;
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::cout << Solution::minSubArrayLen(target, nums);
  return 0;
}
