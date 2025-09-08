#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    const std::size_t nums_size = nums.size();
    if (nums_size < 2) {
      return;
    }
    for (std::ptrdiff_t i = static_cast<std::ptrdiff_t>(nums_size) - 2; i >= 0;
         --i) {
      if (nums[i] < nums[i + 1]) {
        std::swap(nums[i], nums[binSearch(nums, nums_size, i)]);
        std::reverse(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    std::reverse(nums.begin(), nums.end());
  }

private:
  std::ptrdiff_t binSearch(const std::vector<int>& nums,
                           const std::size_t& nums_size,
                           const std::ptrdiff_t& ind) {
    std::ptrdiff_t left = ind + 1;
    std::ptrdiff_t right = static_cast<std::ptrdiff_t>(nums_size);
    while (left + 1 < right) {
      std::ptrdiff_t middle = (left + right) / 2;
      if (nums[middle] > nums[ind]) {
        left = middle;
      } else {
        right = middle;
      }
    }
    return left;
  }
};