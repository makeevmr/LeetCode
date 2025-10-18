#include <vector>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static std::int64_t maxStrength(const std::vector<int>& nums) {
    std::int64_t min_neg = 11;
    std::int64_t total_strength = 1;
    int non_zero_counter = 0;
    for (const int& num : nums) {
      if (num == 0) {
        continue;
      }
      ++non_zero_counter;
      total_strength *= num;
      if (num < 0 && min_neg > -num) {
        min_neg = -num;
      }
    }
    if (total_strength > 0 && non_zero_counter > 0) {
      return total_strength;
    }
    if (non_zero_counter == 0) {
      return 0;
    }
    if (non_zero_counter > 1) {
      return -total_strength / min_neg;
    }
    return nums.size() == 1 ? total_strength : 0;
  }
};