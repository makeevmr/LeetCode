// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.
// Time complexity: O(n)
// Additional memory complexity: O(1)
// Idea: Find max height, the amount of water in the current column will be the difference between
// the current maximum and the current column

#include <iostream>
#include <vector>

class Solution {
public:
    static int trap(const std::vector<int> &height) {
        int max_ind = 0;
        int height_size = static_cast<int>(height.size());
        for (int i = 1; i < height_size; ++i) {
            if (height[max_ind] < height[i]) {
                max_ind = i;
            }
        }
        int water_amount = 0;
        int left_max_height = height[0];
        for (int i = 1; i < max_ind; ++i) {
            if (left_max_height < height[i]) {
                left_max_height = height[i];
            } else {
                water_amount += left_max_height - height[i];
            }
        }
        int right_max_height = height[height_size - 1];
        for (int i = height_size - 2; i > max_ind; --i) {
            if (right_max_height < height[i]) {
                right_max_height = height[i];
            } else {
                water_amount += right_max_height - height[i];
            }
        }
        return water_amount;
    }
};

int main() {
    // std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    std::cout << Solution::trap(height) << '\n';
    return 0;
}