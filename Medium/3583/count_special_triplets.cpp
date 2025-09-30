#include <vector>
#include <unordered_map>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static int specialTriplets(const std::vector<int>& nums) {
    std::uint64_t answer = 0;
    std::unordered_map<int, int> total_freq;
    for (const int& num : nums) {
      ++total_freq[num];
    }
    std::unordered_map<int, int> prefix_freq;
    for (const int& num : nums) {
      const std::uint64_t to_find = num * 2;
      const std::uint64_t left_freq = prefix_freq[to_find];
      std::uint64_t right_freq = total_freq[to_find] - left_freq;
      if (to_find == static_cast<std::uint64_t>(num)) {
        --right_freq;
      }
      answer = (answer + (left_freq * right_freq) % kMod) % kMod;
      ++prefix_freq[num];
    }
    return answer;
  }

private:
  static constexpr std::uint64_t kMod = 1e9 + 7;
};