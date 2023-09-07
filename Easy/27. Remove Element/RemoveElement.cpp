#include <iostream>
#include <vector>

class Solution {
public:
    static int removeElement(std::vector<int> &nums, int val) {
        size_t nums_size = nums.size();
        int right_valid_index = static_cast<int>(nums_size - 1);
        int left_invalid_index = 0;
        while (left_invalid_index < right_valid_index) {
            while ((left_invalid_index < right_valid_index) && (nums[left_invalid_index] != val)) {
                ++left_invalid_index;
            }
            while ((left_invalid_index < right_valid_index) && (nums[right_valid_index] == val)) {
                --right_valid_index;
            }
            if (left_invalid_index < right_valid_index) {
                std::swap(nums[left_invalid_index], nums[right_valid_index]);
                ++left_invalid_index;
                --right_valid_index;
            }
        }
        if (nums_size == 1 && nums[0] == val) {
            --right_valid_index;
        }
        return right_valid_index + 1;
    }
};

int main() {
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int length = Solution::removeElement(nums, val);
    std::cout << length << std::endl;
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
}
