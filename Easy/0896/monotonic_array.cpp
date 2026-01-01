#include <vector>

class Solution {
public:
  [[nodiscard]] static bool isMonotonic(const std::vector<int>& nums) {
    bool is_incr = nums.front() <= nums.back();
    if (const std::size_t nums_size = nums.size(); is_incr) {
      for (std::size_t i = 1; i < nums_size; ++i) {
        if (nums[i - 1] > nums[i]) {
          return false;
        }
      }
    } else {
      for (std::size_t i = 1; i < nums_size; ++i) {
        if (nums[i - 1] < nums[i]) {
          return false;
        }
      }
    }
    return true;
  }
};