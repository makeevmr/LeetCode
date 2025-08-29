/* Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target. You may assume that each input
would have exactly one solution, and you may not use the same element twice. You
can return the answer in any order. Time complexity: O(n), where n is size of
nums Additional memory complexity: O(n) Idea: use unordered_map to store all
possible values and their indexes, iterate through nums and, if value target -
nums[i] in map, return pair of indexes
*/

#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<int> index_pair = {-1, -1};
    std::unordered_map<int, int> first_occurrences = {{nums[0], 0}};
    std::size_t nums_size = nums.size();
    for (std::size_t i = 1; i < nums_size; ++i) {
      if (auto f_iter = first_occurrences.find(target - nums[i]);
          f_iter != first_occurrences.end()) {
        index_pair[0] = f_iter->second;
        index_pair[1] = static_cast<int>(i);
        break;
      }
      if (auto f_iter = first_occurrences.find(nums[i]);
          f_iter == first_occurrences.end()) {
        first_occurrences.insert({nums[i], i});
      }
    }
    return index_pair;
  }
};
