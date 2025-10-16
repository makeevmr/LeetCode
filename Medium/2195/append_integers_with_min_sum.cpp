#include <vector>
#include <cstdint>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::int64_t minimalKSum(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::int64_t answer = 0;
    if (nums[0] != 1) {
      std::int64_t size = std::min(nums[0] - 1, k);
      answer += ((1 + size) * size) / 2;
      k -= size;
    }
    const std::size_t nums_size = nums.size();
    std::size_t i = 1;
    while (k > 0 && i < nums_size) {
      int size = nums[i] - nums[i - 1] - 1;
      if (size < 1) {
        ++i;
        continue;
      }
      size = std::min(size, k);
      answer +=
          ((2 * nums[i - 1] + static_cast<std::int64_t>(size) + 1) * size) / 2;
      k -= size;
      ++i;
    }
    if (k > 0) {
      answer += ((2 * nums.back() + static_cast<std::int64_t>(k) + 1) * k) / 2;
      k = 0;
    }
    return answer;
  }
};