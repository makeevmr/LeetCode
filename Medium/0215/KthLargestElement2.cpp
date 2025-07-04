/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: use std::nth_element
*/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int findKthLargest(std::vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};

int main() {
    // std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    // int k = 2;
    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    std::cout << Solution::findKthLargest(nums, k) << '\n';
    return 0;
}