/* Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the
resulting array. Return 0 if there is no such subarray. Time complexity: O(n)
Additional memory complexity: O(1)
Idea: use prev_segm, new_segment to store number of '1' from two adjacent
segments, when 0 is met prev_segment = new_segment, new_segment = 0;
*/

#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int>& nums) {
    int max_size = 0;
    int prev_segment = 0;
    int new_segment = 0;
    int ind = 0;
    int nums_size = static_cast<int>(nums.size());
    while (ind < nums_size) {
      while (ind < nums_size && nums[ind] == 1) {
        ++new_segment;
        ++ind;
      }
      max_size = std::max(prev_segment + new_segment, max_size);
      prev_segment = new_segment;
      new_segment = 0;
      ++ind;
    }
    if (max_size == nums_size) {
      --max_size;
    }
    return max_size;
  }
};