#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static int maxArea(const std::vector<int> &height) {
        int left_column = 0;
        int right_column = static_cast<int>(height.size()) - 1;
        int max_water = 0;
        while (left_column < right_column) {
            int new_max_water = (right_column - left_column) * std::min(height[left_column], height[right_column]);
            if (max_water < new_max_water) {
                max_water = new_max_water;
            }
            if (height[left_column] > height[right_column]) {
                --right_column;
            } else {
                ++left_column;
            }
        }
        return max_water;
    }
};

int main() {
    std::vector<int> height = {1, 1};
    std::cout << Solution::maxArea(height) << std::endl;
    return 0;
}
