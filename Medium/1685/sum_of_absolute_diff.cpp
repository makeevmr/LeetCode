#include <vector>

class Solution {
public:
  [[nodiscard]] static std::vector<int> getSumAbsoluteDifferences(
      const std::vector<int>& nums) {
    int nums_sum = 0;
    for (const int& num : nums) {
      nums_sum += num;
    }
    int prefix_sum = 0;
    int suffix_sum = nums_sum;
    std::vector<int> result;
    const int nums_size = static_cast<int>(nums.size());
    for (int i = 0; i < nums_size; ++i) {
      suffix_sum -= nums[i];
      result.push_back(suffix_sum - prefix_sum +
                       nums[i] * (2 * i + 1 - nums_size));
      prefix_sum += nums[i];
    }
    return result;
  }
};