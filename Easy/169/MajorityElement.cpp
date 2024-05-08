#include <iostream>
#include <vector>

class Solution {
public:
    // nums length >= 1
    static int majorityElement(const std::vector<int> &nums) {
        int current_major_element = nums[0];
        int major_element_counts = 1;
        size_t nums_size = nums.size();
        for (size_t i = 1; i < nums_size; ++i) {
            if (nums[i] == current_major_element) {
                ++major_element_counts;
            } else {
                --major_element_counts;
                if (major_element_counts == -1) {
                    current_major_element = nums[i];
                    major_element_counts = 1;
                }
            }
        }
        return current_major_element;
    }
};

int main() {
    std::vector<int> nums = {6, 5, 5};
    std::cout << Solution::majorityElement(nums) << std::endl;
    return 0;
}
