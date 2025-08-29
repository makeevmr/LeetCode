/* There is an integer array nums sorted in ascending order (with distinct
values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
Time complexity: O(log(n))
Additional memory complexity: O(1)
Idea: use binay search two times
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int search(const std::vector<int>& nums, int target) {
    int nums_size = static_cast<int>(nums.size());
    int max_pos = getMaxPos(nums);
    int target_pos = 0;
    if (target >= nums[0]) {
      target_pos = binarySearch(nums, 0, max_pos, target);
    } else if (max_pos + 1 < nums_size) {
      target_pos = binarySearch(nums, max_pos + 1, nums_size - 1, target);
    }
    return nums[target_pos] == target ? target_pos : -1;
  }

private:
  [[nodiscard]] static int getMaxPos(const std::vector<int>& nums) {
    int first_group_min = nums[0];
    int left = 0;
    int right = static_cast<int>(nums.size());
    while (left < right - 1) {
      int middle = (left + right) >> 1;
      if (nums[middle] < first_group_min) {
        right = middle;
      } else {
        left = middle;
      }
    }
    return left;
  }

  [[nodiscard]] static int binarySearch(const std::vector<int>& nums, int left,
                                        int right, int target) {
    while (left < right) {
      int middle = (left + right) >> 1;
      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }
};
