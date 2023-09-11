#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static void rotate(std::vector<int> &nums, int k) {
        int rotates = k % static_cast<int>(nums.size());
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + rotates);
        std::reverse(nums.begin() + rotates, nums.end());
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution::rotate(nums, 2);
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
    return 0;
}