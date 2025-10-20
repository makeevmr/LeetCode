#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int minimumBoxes(const std::vector<int>& apple,
                                        std::vector<int>& capacity) {
    int apples_sum = 0;
    for (const int& pack_size : apple) {
      apples_sum += pack_size;
    }
    std::sort(capacity.rbegin(), capacity.rend());
    int ind = 0;
    while (apples_sum > 0) {
      apples_sum -= capacity[ind++];
    }
    return ind;
  }
};