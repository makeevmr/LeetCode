#include <vector>
#include <numeric>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static int waysToSplitArray(const std::vector<int>& nums) {
    const std::size_t nums_size = nums.size();
    const std::int64_t nums_sum =
        std::accumulate(nums.begin(), nums.end(), 0LL);
    int valid_splits = 0;
    std::int64_t pref_sum = 0;
    for (std::size_t i = 0; i < nums_size - 1; ++i) {
      pref_sum += nums[i];
      if (2 * pref_sum >= nums_sum) {
        ++valid_splits;
      }
    }
    return valid_splits;
  }
};