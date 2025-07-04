// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.
// Time complexity: O(n)
// Additional memory complexity: O(1)
// Idea: Use two pointers, the amount of water in the current column will be the difference between
// the current maximum and the current column

#include <iostream>
#include <vector>

class Solution {
public:
    static int trap(const std::vector<int> &height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_left_height = -1;
        int max_right_height = -1;
        int water_amount = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] > max_left_height) {
                    max_left_height = height[left];
                } else {
                    water_amount += max_left_height - height[left];
                }
                ++left;
            } else {
                if (height[right] > max_right_height) {
                    max_right_height = height[right];
                } else {
                    water_amount += max_right_height - height[right];
                }
                --right;
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
