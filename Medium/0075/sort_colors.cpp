/* Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent, with the colors in the
order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and
blue, respectively.

You must solve this problem without using the library's sort function. */

#include <vector>

class Solution {
public:
  static void sortColors(std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    int left_ptr = 0;
    int right_ptr = nums_size - 1;
    while (left_ptr < right_ptr) {
      while ((left_ptr < right_ptr) && (nums[left_ptr] == 0)) {
        ++left_ptr;
      }
      while ((left_ptr < right_ptr) && (nums[right_ptr] != 0)) {
        --right_ptr;
      }
      if (left_ptr < right_ptr) {
        std::swap(nums[left_ptr], nums[right_ptr]);
        ++left_ptr;
        --right_ptr;
      }
    }
    while ((left_ptr < nums_size) && nums[left_ptr] == 0) {
      ++left_ptr;
    }
    right_ptr = static_cast<int>(nums.size() - 1);
    while (left_ptr < right_ptr) {
      while ((left_ptr < right_ptr) && (nums[left_ptr] == 1)) {
        ++left_ptr;
      }
      while ((left_ptr < right_ptr) && (nums[right_ptr] != 1)) {
        --right_ptr;
      }
      if (left_ptr < right_ptr) {
        std::swap(nums[left_ptr], nums[right_ptr]);
        ++left_ptr;
        --right_ptr;
      }
    }
  }
};
