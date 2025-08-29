#include <iostream>
#include <vector>

class Solution {
public:
  static int removeDuplicates(std::vector<int>& nums) {
    short int value_appearances = 1;
    int push_back_index = 1;
    size_t nums_size = nums.size();
    int current_value = nums_size > 0 ? nums[0] : 0;
    for (size_t i = 1; i < nums_size; ++i) {
      if (nums[i] > current_value) {
        current_value = nums[i];
        nums[push_back_index] = nums[i];
        ++push_back_index;
        value_appearances = 1;
      } else if ((nums[i] == current_value) && (value_appearances == 1)) {
        ++value_appearances;
        nums[push_back_index] = nums[i];
        ++push_back_index;
      }
    }
    return nums_size > 0 ? push_back_index : 0;
  }
};

int main() {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int length = Solution::removeDuplicates(nums);
  std::cout << length << std::endl;
  for (size_t i = 0; i < length; ++i) {
    std::cout << nums[i] << ' ';
  }
  return 0;
}
