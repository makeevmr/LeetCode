/* Given an array of integers nums and an integer k, return the number of
 * contiguous subarrays where the product of all the elements in the subarray is
 * strictly less than k. */

#include <vector>

class Solution {
public:
  static int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
    int nums_size = static_cast<int>(nums.size());
    int left = -1;
    int subarray_product = 1;
    int counter = 0;
    for (int right = 0; right < nums_size; ++right) {
      subarray_product *= nums[right];
      while ((left < right) && (subarray_product >= k)) {
        ++left;
        subarray_product /= nums[left];
      }
      counter += right - left;
    }
    return counter;
  }
};