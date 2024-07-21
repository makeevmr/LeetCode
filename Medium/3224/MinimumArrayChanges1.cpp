/* You are given an integer array nums of size n where n is even, and an integer k.
You can perform some changes on the array, where in one change you can replace any element in the
array with any integer in the range from 0 to k.
You need to perform some changes (possibly none) such that the final array satisfies the following
condition:
There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).
Return the minimum number of changes required to satisfy the above condition. */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static int minChanges(const std::vector<int> &nums, int k) {
        std::vector<int> abs_count(k + 1, 0);
        std::vector<int> max_diff_count(k + 1, 0);
        int nums_size = static_cast<int>(nums.size());
        int curr_ind = 0;
        while (curr_ind < nums_size / 2) {
            const int &n1 = nums[curr_ind];
            const int &n2 = nums[nums_size - curr_ind - 1];
            int max_diff = std::max(std::max(n1, n2), k - std::min(n1, n2));
            ++abs_count[abs(n1 - n2)];
            ++max_diff_count[max_diff];
            ++curr_ind;
        }
        int min_answer = nums_size;
        int curr_sum = 0;
        for (int i = k; i >= 0; --i) {
            curr_sum += max_diff_count[i];
            int countGroupRight = curr_sum - abs_count[i];
            int countGroupLeft = nums_size / 2 - countGroupRight - abs_count[i];
            int new_answer = countGroupLeft * 2 + countGroupRight;
            min_answer = std::min(min_answer, new_answer);
        }
        return min_answer;
    }
};

int main() {
    std::vector<int> nums = {1, 0, 1, 2, 4, 3};
    int k = 4;
    // std::vector<int> nums = {0, 1, 2, 3, 3, 6, 5, 4};
    // int k = 6;
    std::cout << Solution::minChanges(nums, k) << '\n';
    return 0;
}
