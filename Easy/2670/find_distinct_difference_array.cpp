#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  [[nodiscard]] static std::vector<int> distinctDifferenceArray(
      const std::vector<int>& nums) {
    std::unordered_map<int, int> num_freq;
    for (const int& num : nums) {
      ++num_freq[num];
    }
    int suffix_unique = static_cast<int>(num_freq.size());
    std::vector<int> answer;
    std::unordered_set<int> pref_unique;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      if (num_freq[nums[i]]-- == 1) {
        --suffix_unique;
      }
      pref_unique.insert(nums[i]);
      answer.push_back(static_cast<int>(pref_unique.size()) - suffix_unique);
    }
    return answer;
  }
};