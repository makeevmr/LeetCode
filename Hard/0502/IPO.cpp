/* Suppose LeetCode will start its IPO soon. In order to sell a good price of
its shares to Venture Capital, LeetCode would like to work on some projects to
increase its capital before the IPO. Since it has limited resources, it can only
finish at most k distinct projects before the IPO. Help LeetCode design the best
way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and
a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its
pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your
final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
Time complexity: O(n * log(n))
Additional memory complexity: O(n)
Idea: sort array {capital, profits}, create max_heap and insert all available
profits at the moment
*/

#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int findMaximizedCapital(
      int k, int w, const std::vector<int>& profits,
      const std::vector<int>& capital) {
    std::vector<std::pair<int, int>> cap_prof_map;
    std::size_t capital_size = capital.size();
    for (std::size_t i = 0; i < capital_size; ++i) {
      cap_prof_map.push_back(std::pair<int, int>{capital[i], profits[i]});
    }
    std::sort(cap_prof_map.begin(), cap_prof_map.end(),
              [](const std::pair<int, int>& l, const std::pair<int, int>& r) {
                return l.first < r.first;
              });
    std::size_t map_ind = 0;
    std::priority_queue<int> available_profits_heap;
    while (k-- > 0) {
      while (map_ind < capital_size && w >= cap_prof_map[map_ind].first) {
        available_profits_heap.push(cap_prof_map[map_ind].second);
        ++map_ind;
      }
      if (available_profits_heap.empty()) {
        break;
      }
      w += available_profits_heap.top();
      available_profits_heap.pop();
    }
    return w;
  }
};