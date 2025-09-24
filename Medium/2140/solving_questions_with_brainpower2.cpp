#include <cstdint>
#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::int64_t mostPoints(
      const std::vector<std::vector<int>>& questions) {
    const int questions_size = static_cast<int>(questions.size());
    std::vector<std::int64_t> dp(questions_size, 0);
    dp[0] = questions[0][0];
    if ((questions[0][1] + 1) < questions_size) {
      dp[questions[0][1] + 1] = dp[0];
    }
    std::int64_t base_num = 0;
    for (int i = 1; i < questions_size; ++i) {
      base_num = std::max(base_num, dp[i]);
      dp[i] = std::max(dp[i], base_num);
      if (const int step_ind = i + questions[i][1] + 1;
          step_ind < questions_size) {
        dp[step_ind] = std::max(dp[step_ind], dp[i] + questions[i][0]);
      }
      if (dp[i] + questions[i][0] > dp[i - 1]) {
        dp[i] += questions[i][0];
      } else {
        dp[i] = dp[i - 1];
      }
    }
    return dp.back();
  }
};