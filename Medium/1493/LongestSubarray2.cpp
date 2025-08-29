#include <iostream>
#include <vector>

class Solution {
public:
  static int longestSubarray(std::vector<int>& nums) {
    int max_size = 0;
    int prev_size = 0;
    int current_size = 0;
    for (const auto& num : nums) {
      if (num == 0) {
        if ((prev_size + current_size) > max_size) {
          max_size = prev_size + current_size;
        }
        prev_size = current_size;
        current_size = 0;
      } else {
        ++current_size;
      }
    }
    if ((prev_size + current_size) > max_size) {
      max_size = prev_size + current_size;
    }
    if (static_cast<std::size_t>(max_size) == nums.size()) {
      --max_size;
    }
    return max_size;
  }
};

int main() {
  // std::vector<int> nums = {1, 1, 0, 1};
  // std::vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  std::vector<int> nums = {1, 1, 1};
  std::cout << Solution::longestSubarray(nums) << '\n';
  return 0;
}
