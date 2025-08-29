/* Given an array nums of distinct integers, return all the possible
permutations. You can return the answer in any order. Time complexity: O(n * n!)
Additional memory complexity: O(n)
Idea: use std::swap to calculate all permutations
*/

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int nums_size = static_cast<int>(nums.size());
    getPermutations(nums, 0, nums_size);
    return result;
  }

private:
  void getPermutations(std::vector<int>& nums, int level,
                       const int& nums_size) {
    if (level == nums_size) {
      result.push_back(nums);
      return;
    }
    for (int i = level; i < nums_size; ++i) {
      std::swap(nums[level], nums[i]);
      getPermutations(nums, level + 1, nums_size);
      std::swap(nums[level], nums[i]);
    }
  }

  std::vector<std::vector<int>> result;
};

int main() {
  Solution solve;
  std::vector<int> nums = {1, 2, 3};
  // std::vector<int> nums = {0, 1};
  // std::vector<int> nums = {1};
  std::vector<std::vector<int>> permutations = solve.permute(nums);
  for (const auto& perm : permutations) {
    for (const auto& num : perm) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}