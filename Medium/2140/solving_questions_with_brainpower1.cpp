#include <cstdint>
#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::int64_t mostPoints(
      const std::vector<std::vector<int>>& questions) {
    const int questions_size = static_cast<int>(questions.size());
    std::vector<std::int64_t> dp(questions_size, 0);
    for (int i = questions_size - 1; i >= 0; --i) {
      dp[i] = questions[i][0];
      if (const int next_ind = i + questions[i][1] + 1;
          next_ind < questions_size) {
        dp[i] += dp[next_ind];
      }
      if (i < questions_size - 1) {
        dp[i] = std::max(dp[i], dp[i + 1]);
      }
    }
    return dp.front();
  }
};
