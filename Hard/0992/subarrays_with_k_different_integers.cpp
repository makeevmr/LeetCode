/* Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A good array is an array where the number of different integers in that array is
exactly k.

    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A subarray is a contiguous part of an array. */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static int subarraysWithKDistinct(std::vector<int>& nums,
                                                  int k) {
    int counter = 0;
    int left = -1;
    int right = -1;
    int last_occurance_ind = 0;
    int nums_size = static_cast<int>(nums.size());
    int unique_nums = 0;
    std::unordered_map<int, int> nums_freq_map;
    std::unordered_map<int, int> last_occurances_map;
    while ((right + 1) < nums_size) {
      while (((right + 1) < nums_size) && (unique_nums < k)) {
        ++right;
        ++nums_freq_map[nums[right]];
        last_occurances_map[nums[right]] = right;
        if (nums_freq_map[nums[right]] == 1) {
          ++unique_nums;
        }
      }
      if (unique_nums == k) {
        last_occurance_ind = left + 1;
        while (last_occurances_map[nums[last_occurance_ind]] !=
               last_occurance_ind) {
          ++last_occurance_ind;
        }
        counter += last_occurance_ind - left;
        while (((right + 1) < nums_size) &&
               (nums_freq_map[nums[right + 1]] != 0)) {
          ++right;
          ++nums_freq_map[nums[right]];
          last_occurances_map[nums[right]] = right;
          while (last_occurances_map[nums[last_occurance_ind]] !=
                 last_occurance_ind) {
            ++last_occurance_ind;
          }
          counter += last_occurance_ind - left;
        }
      }
      while (left < last_occurance_ind) {
        ++left;
        --nums_freq_map[nums[left]];
      }
      --unique_nums;
    }
    return counter;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  std::cout << Solution::subarraysWithKDistinct(nums, k) << '\n';
  return 0;
}
