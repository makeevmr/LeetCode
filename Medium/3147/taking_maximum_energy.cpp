#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int maximumEnergy(const std::vector<int>& energy,
                                         int k) {
    int max_energy = std::numeric_limits<int>::min();
    const std::size_t energy_size = energy.size();
    std::vector<int> dp(energy_size, 0);
    for (std::size_t i = 0; i < energy_size; ++i) {
      dp[i] = energy[i];
      if (i >= static_cast<std::size_t>(k)) {
        dp[i] += std::max(dp[i - k], 0);
      }
      if (i + k >= energy_size) {
        max_energy = std::max(max_energy, dp[i]);
      }
    }
    return max_energy;
  }
};