#include <vector>
#include <stack>

class Solution {
public:
  [[nodiscard]] static std::vector<int> dailyTemperatures(
      const std::vector<int>& temperatures) {
    size_t temperatures_size = temperatures.size();
    std::stack<int> unresolved_days;
    std::vector<int> answer(temperatures_size, 0);
    for (size_t i = 0; i < temperatures_size; ++i) {
      while (!unresolved_days.empty() &&
             temperatures[unresolved_days.top()] < temperatures[i]) {
        answer[unresolved_days.top()] =
            static_cast<int>(i) - unresolved_days.top();
        unresolved_days.pop();
      }
      unresolved_days.push(i);
    }
    return answer;
  }
};