/* You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the
array exactly. That is, each element of nums is covered by exactly one of the
ranges, and there is no integer x such that x is in one of the ranges but not in
nums. Each range [a,b] in the list should be output as: "a->b" if a != b "a" if
a == b Time complexity: O(n) Additional memory complexiy: O(1) Idea: iterate
through nums and store all intervals
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
    std::vector<std::string> answer;
    std::size_t curr_index = 0;
    std::size_t nums_size = nums.size();
    while (curr_index < nums_size) {
      std::size_t left_border = curr_index;
      while ((curr_index < nums_size - 1) &&
             (nums[curr_index] == nums[curr_index + 1] - 1)) {
        ++curr_index;
      }
      if (curr_index != left_border) {
        answer.push_back(std::to_string(nums[left_border]) + "->" +
                         std::to_string(nums[curr_index]));
      } else {
        answer.push_back(std::to_string(nums[left_border]));
      }
      ++curr_index;
    }
    return answer;
  }
};

int main() {
  // std::vector<int> nums = {0, 1, 2, 4, 5, 7};
  std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
  std::vector<std::string> answer = Solution::summaryRanges(nums);
  for (const auto& item : answer) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
  return 0;
}
