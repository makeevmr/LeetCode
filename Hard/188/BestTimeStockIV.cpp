/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock
before you buy again).
Time complexity: O(k * n)
Additional memory complexity: O(k * n)
Idea: dp[k][i] where k is number of (buy, sell) pairs, i is number of day
*/

#include <vector>
#include <limits>

class Solution {
public:
    [[nodiscard]] static int maxProfit(int k, const std::vector<int>& prices) {
        int operations = k + 1;
        int days = static_cast<int>(prices.size());
        std::vector<std::vector<int>> dp(operations, std::vector<int>(days + 1, 0));
        int answer = 0;
        for (int k = 1; k < operations; ++k) {
            int min_consumption = std::numeric_limits<int>::min();
            for (int i = 1; i <= days; ++i) {
                dp[k][i] = std::max(dp[k][i - 1], prices[i - 1] + min_consumption);
                min_consumption = std::max(min_consumption, dp[k - 1][i - 1] - prices[i - 1]);
            }
            answer = std::max(answer, dp[k].back());
        }
        return answer;
    }
};