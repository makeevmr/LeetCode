#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int countWays(std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    std::sort(nums.begin(), nums.end());
    int happy_counter = 0;
    for (int i = 1; i < nums_size - 1; ++i) {
      if (nums[i - 1] < i && i < nums[i]) {
        ++happy_counter;
      }
    }
    if (0 < nums[0]) {
      ++happy_counter;
    }
    if (nums[nums_size - 1] < nums_size) {
      ++happy_counter;
    }
    return happy_counter;
  }
};