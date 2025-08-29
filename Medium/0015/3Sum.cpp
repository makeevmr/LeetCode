#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int nums_size = nums.size();
    std::vector<std::vector<int>> answer;
    for (int fixed_index = 0; fixed_index < nums_size; ++fixed_index) {
      int left_index = fixed_index + 1;
      int right_index = nums_size - 1;
      int value_to_find = -nums[fixed_index];
      while (left_index < right_index) {
        int sum = nums[left_index] + nums[right_index];
        if (sum < value_to_find) {
          ++left_index;
        } else if (sum > value_to_find) {
          --right_index;
        } else {
          std::vector<int> triplet = {nums[fixed_index], nums[left_index],
                                      nums[right_index]};
          answer.push_back(triplet);
          while (left_index < right_index && nums[left_index] == triplet[1]) {
            ++left_index;
          }
          while (left_index < right_index && nums[right_index] == triplet[2]) {
            --right_index;
          }
        }
      }
      while (fixed_index + 1 < nums_size &&
             nums[fixed_index + 1] == nums[fixed_index]) {
        ++fixed_index;
      }
    }
    return answer;
  }
};

int main() {
  std::vector<int> nums = {0, 0, 0, 0};
  std::vector<std::vector<int>> answer = Solution::threeSum(nums);
  std::cout << '[';
  for (std::vector<int> vec : answer) {
    std::cout << '[';
    for (int i : vec) {
      std::cout << i << ", ";
    }
    std::cout << ']';
  }
  std::cout << ']' << std::endl;
  return 0;
}
