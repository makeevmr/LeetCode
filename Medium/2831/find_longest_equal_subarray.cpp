#include <vector>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static int longestEqualSubarray(const std::vector<int>& nums,
                                                int k) {
    const int nums_size = static_cast<int>(nums.size());
    std::unordered_map<int, int> freq;
    int i = 0;
    int j = 0;
    int answer = 1;
    ++freq[nums[i]];
    while (j + 1 < nums_size) {
      ++j;
      ++freq[nums[j]];
      int seg_size = j - i + 1;
      while ((seg_size - freq[nums[i]] > k) && (seg_size - freq[nums[j]] > k)) {
        --freq[nums[i]];
        ++i;
        --seg_size;
      }
      answer = std::max(answer, std::max(freq[nums[i]], freq[nums[j]]));
    }
    return answer;
  }
};