#include <iostream>
#include <vector>

class Solution {
public:
  static std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int prefix_product = 1;
    int suffix_product = 1;
    std::vector<int> answer;
    size_t nums_size = nums.size();
    for (size_t i = 0; i < nums_size; ++i) {
      answer.push_back(prefix_product);
      prefix_product *= nums[i];
    }
    for (int i = static_cast<int>(nums_size - 1); i >= 0; --i) {
      answer[i] *= suffix_product;
      suffix_product *= nums[i];
    }
    return answer;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> answer = Solution::productExceptSelf(nums);
  for (size_t i = 0; i < answer.size(); ++i) {
    std::cout << answer[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}