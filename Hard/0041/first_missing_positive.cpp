#include <vector>

class Solution {
public:
  [[nodiscard]] static int firstMissingPositive(std::vector<int>& nums) {
    const int nums_size = static_cast<int>(nums.size());
    int answer = nums_size + 1;
    int i = nums_size - 1;
    while (i >= 0) {
      if (nums[i] == i + 1) {
        --i;
        continue;
      }
      if ((nums[i] <= 0) || (nums[i] > i + 1)) {
        answer = i + 1;
        --i;
        continue;
      }
      while ((1 <= nums[i]) && (nums[i] <= i)) {
        if (nums[nums[i] - 1] == nums[i]) {
          answer = i + 1;
          --i;
          break;
        }
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }
    return answer;
  }
};