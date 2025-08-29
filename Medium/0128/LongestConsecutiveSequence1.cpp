/* Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence. You must write an algorithm that runs in O(n)
time. Time complexity: O(n) Additional memory complexity: O(n) Idea: use
unordered_set to store unique numbers, iterate through nums and calculate
sequence length if curr number is start of sequence
*/

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> unique_nums(nums.begin(), nums.end());
    int max_seq_len = 0;
    for (const auto& num : nums) {
      if (unique_nums.contains(num - 1)) {
        continue;
      }
      int curr_seq_len = 1;
      while (unique_nums.contains(num + curr_seq_len)) {
        ++curr_seq_len;
      }
      max_seq_len = std::max(max_seq_len, curr_seq_len);
    }
    return max_seq_len;
  }
};

int main() {
  // std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::cout << Solution::longestConsecutive(nums) << '\n';
  return 0;
}
