/* Given a sorted array of distinct integers and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
Time complexity: O(log(n))
Additional memory complexity: O(1)
Idea: use binary search
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int searchInsert(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        while (left < right) {
            int middle = (left + right) >> 1;
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        if (nums[left] >= target) {
            return left;
        }
        return left + 1;
    }
};
