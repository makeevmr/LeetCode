#include <iostream>
#include <vector>

class Solution {
public:
    static int removeElement(std::vector<int> &nums, int val) {
        size_t nums_size = nums.size();
        int left_invalid_index = 0;
        int right_valid_index = static_cast<int>(nums_size - 1);
        while (left_invalid_index <= right_valid_index) {
            while ((left_invalid_index < nums_size) && (nums[left_invalid_index] != val)) {
                ++left_invalid_index;
            }
            while ((right_valid_index >= 0) && (nums[right_valid_index] == val)) {
                --right_valid_index;
            }
            if (left_invalid_index < right_valid_index) {
                std::swap(nums[left_invalid_index], nums[right_valid_index]);
                ++left_invalid_index;
                --right_valid_index;
            }
        }
        return right_valid_index + 1;
    }
};

int main() {
    std::vector<int> nums = {1};
    int val = 1;
    int length = Solution::removeElement(nums, val);
    std::cout << length << std::endl;
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
}
