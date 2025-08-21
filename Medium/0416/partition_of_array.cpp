/* Given an integer array nums, return true if you can partition the array into
two subsets such that the sum of the elements in both subsets is equal or
false otherwise.
*/

#include <bits/stdc++.h>

class Solution {
public:
    [[nodiscard]] static bool canPartition(const std::vector<int>& nums) {
        int nums_sum = 0;
        for (const int& num : nums) {
            nums_sum += num;
        }
        if (nums_sum % 2 == 1) {
            return false;
        }
        std::unordered_set<int> founded_sums = {0};
        std::queue<int> queue_sums;
        int target_sum = nums_sum / 2;
        for (const int& num : nums) {
            size_t founded_sums_size = founded_sums.size();
            if (founded_sums.contains(target_sum - num)) {
                return true;
            }
            for (auto f_iter = founded_sums.begin();
                 f_iter != founded_sums.end(); ++f_iter) {
                int new_sum = *f_iter + num;
                if ((new_sum < target_sum) && !founded_sums.contains(new_sum)) {
                    queue_sums.push(new_sum);
                }
            }
            while (!queue_sums.empty()) {
                founded_sums.insert(queue_sums.front());
                queue_sums.pop();
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 5, 11, 5};
    assert(Solution::canPartition(nums));
    nums = {1, 2, 3, 5};
    assert(!Solution::canPartition(nums));
    return 0;
}