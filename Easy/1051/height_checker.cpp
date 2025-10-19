#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int heightChecker(const std::vector<int>& heights) {
    std::vector<int> sorted_heights = heights;
    std::sort(sorted_heights.begin(), sorted_heights.end());
    int answer = 0;
    for (std::size_t i = 0; i < sorted_heights.size(); ++i) {
      if (sorted_heights[i] != heights[i]) {
        ++answer;
      }
    }
    return answer;
  }
};