#include <iostream>
#include <vector>

class Solution {
public:
    static void rotate(std::vector<int> &nums, int k) {
        size_t nums_size = nums.size();
        size_t rotates = static_cast<size_t>(k) % nums_size;
        for (size_t i = nums_size - rotates; i < nums_size; ++i) {
            int end_swap_index = static_cast<int>(i + rotates - nums_size);
            for (int j = i - 1; j >= end_swap_index; --j) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
};

int main() {
    std::vector<int> nums = {-1, -100, 3, 99};
    Solution::rotate(nums, 2);
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
    return 0;
}