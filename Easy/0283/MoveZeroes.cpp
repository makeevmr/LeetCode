/* Given an integer array nums, move all 0's to the end of it while maintaining
the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    int zero_ind = 0;
    while (zero_ind < nums_size && nums[zero_ind] != 0) {
      ++zero_ind;
    }
    int non_zero_ind = zero_ind;
    while (zero_ind < nums_size && non_zero_ind < nums_size) {
      while (zero_ind < nums_size && nums[zero_ind] != 0) {
        ++zero_ind;
      }
      while (non_zero_ind < nums_size && nums[non_zero_ind] == 0) {
        ++non_zero_ind;
      }
      if (non_zero_ind < nums_size && zero_ind < nums_size) {
        std::swap(nums[non_zero_ind], nums[zero_ind]);
        ++non_zero_ind;
        ++zero_ind;
      }
    }
  }
};
