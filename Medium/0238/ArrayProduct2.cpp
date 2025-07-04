#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> productExceptSelf(const std::vector<int> &nums) {
        std::vector<int> prefix_product_array;
        std::vector<int> suffix_product_array;
        int prefix_product = 1;
        int suffix_product = 1;
        size_t nums_size = nums.size();
        for (size_t i = 0; i < nums_size; ++i) {
            prefix_product_array.push_back(prefix_product);
            suffix_product_array.push_back(suffix_product);
            prefix_product *= nums[i];
            suffix_product *= nums[nums_size - i - 1];
        }
        std::vector<int> answer;
        for (size_t i = 0; i < nums_size; ++i) {
            answer.push_back(prefix_product_array[i] * suffix_product_array[nums_size - 1 - i]);
        }
        return answer;
    }
};

int main() {
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> answer = Solution::productExceptSelf(nums);
    for (size_t i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
