/* A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
always considered to be strictly greater than a neighbor that is outside the
array.

You must write an algorithm that runs in O(log n) time.
No adjacent two numbers are the same
Time complexity: O(log(n))
Additional memory complexity: O(1)
Idea: use binary search
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int findPeakElement(const std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    if (nums_size == 1) {
      return 0;
    }
    int left = 0;
    int right = nums_size - 1;
    while (left < right) {
      int middle = (left + right) >> 1;
      if (middle == left) {
        return nums[left] > nums[right] ? left : right;
      }
      if ((nums[middle - 1] < nums[middle]) &&
          (nums[middle] < nums[middle + 1])) {
        left = middle;
      } else {
        right = middle;
      }
    }
    return left;
  }
};
