#include <vector>
#include <deque>

class Solution {
public:
  [[nodiscard]] static std::vector<int> maxSlidingWindow(
      const std::vector<int>& nums, int k) {
    std::deque<std::pair<int, int>> deq;
    std::vector<int> ans;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      while (!deq.empty() && deq.front().second <= i - k) {
        deq.pop_front();
      }
      while (!deq.empty() && deq.back().first < nums[i]) {
        deq.pop_back();
      }
      deq.push_back(std::pair<int, int>{nums[i], i});
      if (i >= (k - 1)) {
        ans.push_back(deq.front().first);
      }
    }
    return ans;
  }
};