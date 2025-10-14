#include <vector>
#include <cmath>
#include <limits>

class Solution {
public:
  int longestSubsequence(const std::vector<int>& nums) {
    const int nums_size = static_cast<int>(nums.size());
    const int dp_size = 301;
    int dp[dp_size][dp_size] = {};
    for (int i = nums_size - 1; i >= 0; --i) {
      const int& num = nums[i];
      for (int next = 1; next < dp_size; ++next) {
        const int diff = std::abs(next - num);
        dp[num][diff] = std::max(dp[num][diff], dp[next][diff] + 1);
      }
      for (int diff = 1; diff < dp_size - 1; ++diff) {
        dp[num][diff] = std::max(dp[num][diff], dp[num][diff - 1]);
      }
    }
    int answer = std::numeric_limits<int>::min();
    for (int i = 1; i < dp_size; ++i) {
      for (int j = 0; j < dp_size - 1; ++j) {
        answer = std::max(answer, dp[i][j]);
      }
    }
    return answer;
  }
};