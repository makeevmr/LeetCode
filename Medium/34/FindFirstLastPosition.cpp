/* Given an array of integers nums sorted in non-decreasing order, find the starting and ending
position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        std::vector<int> answer(2, -1);
        if (nums.empty()) {
            return answer;
        }
        answer[0] = leftBinarySearch(nums, target);
        if (nums[answer[0]] != target) {
            return {-1, -1};
        }
        answer[1] = rightBinarySearch(nums, target);
        return answer;
    }

private:
    [[nodiscard]] static int leftBinarySearch(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int middle = (left + right) >> 1;
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        return left;
    }

    [[nodiscard]] static int rightBinarySearch(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());
        while (left < right - 1) {
            int middle = (left + right) >> 1;
            if (nums[middle] <= target) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return left;
    }
};