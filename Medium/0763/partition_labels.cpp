#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static std::vector<int> partitionLabels(const std::string& s) {
    size_t s_size = s.size();
    std::unordered_map<char, size_t> last_occurance_map;
    for (size_t i = 0; i < s_size; ++i) {
      last_occurance_map[s[i]] = i;
    }
    size_t seg_start = 0;
    size_t seg_end = 0;
    std::vector<int> ans;
    for (size_t i = 0; i < s_size; ++i) {
      seg_end = std::max(seg_end, last_occurance_map[s[i]]);
      if (i == seg_end) {
        ans.push_back(static_cast<int>(seg_end - seg_start + 1));
        seg_start = i + 1;
      }
    }
    return ans;
  }
};