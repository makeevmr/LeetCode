#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
  [[nodiscard]] static std::vector<int> topKFrequent(
      const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> num_freq_map;
    for (const int& num : nums) {
      ++num_freq_map[num];
    }
    std::priority_queue<std::pair<int, int>> max_freq_heap;
    for (const auto& [num, freq] : num_freq_map) {
      max_freq_heap.emplace(freq, num);
    }
    std::vector<int> ans;
    while (k > 0) {
      ans.push_back(max_freq_heap.top().second);
      --k;
      max_freq_heap.pop();
    }
    return ans;
  }
};