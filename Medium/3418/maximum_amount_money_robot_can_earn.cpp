#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int maximumAmount(
      const std::vector<std::vector<int>>& coins) {
    const int rows = static_cast<int>(coins.size());
    const int columns = static_cast<int>(coins.front().size());
    std::vector<std::vector<std::vector<int>>> dp(
        rows, std::vector<std::vector<int>>(columns, std::vector<int>(3, 0)));
    dp[0][0][0] = coins[0][0];
    dp[0][0][1] = std::max(dp[0][0][0], 0);
    dp[0][0][2] = std::max(dp[0][0][1], 0);
    for (int i = 1; i < rows; ++i) {
      dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
      dp[i][0][1] = std::max(
          {dp[i - 1][0][1] + coins[i][0], dp[i - 1][0][0], dp[i][0][0]});
      dp[i][0][2] = std::max(
          {dp[i - 1][0][2] + coins[i][0], dp[i - 1][0][1], dp[i][0][1]});
    }
    for (int j = 1; j < columns; ++j) {
      dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
      dp[0][j][1] = std::max(
          {dp[0][j - 1][1] + coins[0][j], dp[0][j - 1][0], dp[0][j][0]});
      dp[0][j][2] = std::max(
          {dp[0][j - 1][2] + coins[0][j], dp[0][j - 1][1], dp[0][j][1]});
    }
    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < columns; ++j) {
        dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
        dp[i][j][1] =
            std::max({std::max(dp[i - 1][j][1], dp[i][j - 1][1]) + coins[i][j],
                      dp[i - 1][j][0], dp[i][j - 1][0], dp[i][j][0]});
        dp[i][j][2] =
            std::max({std::max(dp[i - 1][j][2], dp[i][j - 1][2]) + coins[i][j],
                      dp[i - 1][j][1], dp[i][j - 1][1], dp[i][j][1]});
      }
    }
    return dp[rows - 1][columns - 1][2];
  }
};