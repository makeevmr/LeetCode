#include <iostream>
#include <vector>

class Solution {
public:
  static int removeDuplicates(std::vector<int>& nums) {
    size_t push_back_index = 0;
    int current_value = -101;
    size_t nums_size = nums.size();
    for (size_t i = 0; i < nums_size; ++i) {
      if (nums[i] > current_value) {
        current_value = nums[i];
        nums[push_back_index] = nums[i];
        ++push_back_index;
      }
    }
    return push_back_index;
  }
};

int main() {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int length = Solution::removeDuplicates(nums);
  std::cout << length << std::endl;
  for (size_t i = 0; i < length; ++i) {
    std::cout << nums[i] << ' ';
  }
}
