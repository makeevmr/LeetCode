/* You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent
houses have security systems connected and it will automatically contact the police if two adjacent
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum
amount of money you can rob tonight without alerting the police.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: dynamic programming (max value we can get robbing banks in range [0..i])
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] static int rob(const std::vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        for (const auto& val : nums) {
            int tmp = prev1;
            prev1 = std::max(prev1, prev2 + val);
            prev2 = tmp;
        }
        return prev1;
    }
};