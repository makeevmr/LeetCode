#include <vector>
#include <limits>

class Solution {
public:
  [[nodiscard]] static int maxProfit(const std::vector<int>& prices) {
    int state0 = 0;                                // pass current prices[i]
    int state1 = -prices[0];                       // buy current prices[i]
    int state2 = std::numeric_limits<int>::min();  // cooldown state
    for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
      int new_state0 = std::max(state0, state2);
      int new_state1 = std::max(state1, state0 - prices[i]);
      int new_state2 = state1 + prices[i];
      state0 = new_state0;
      state1 = new_state1;
      state2 = new_state2;
    }
    return std::max(state0, state2);
  }
};