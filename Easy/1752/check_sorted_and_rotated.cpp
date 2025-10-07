#include <vector>
class Solution {
public:
  [[nodiscard]] static bool check(const std::vector<int>& nums) {
    const std::size_t nums_size = nums.size();
    if (nums_size == 1ULL) {
      return true;
    }
    std::size_t disorder_count = 0;
    for (std::size_t i = 1; i < nums_size; ++i) {
      if (nums[i - 1] > nums[i]) {
        ++disorder_count;
      }
      if (disorder_count > 1) {
        return false;
      }
    }
    if (disorder_count == 0) {
      return true;
    }
    return nums.front() >= nums.back();
  }
};