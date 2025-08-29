/* Suppose an array of length n sorted in ascending order is rotated between 1
and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum
element of this array.

You must write an algorithm that runs in O(log n) time.
Time complexity: O(log(n))
Additional memory complexity: O(1)
Idea: use binary search
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int second_group_num = nums.back();
    while (left < right) {
      int middle = (left + right) >> 1;
      if (nums[middle] > second_group_num) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return nums[left];
  }
};