#include <vector>

class CustomFunction {
public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  int f(int x, int y);
};

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<int>> findSolution(
      CustomFunction& customfunction, int z) {
    std::vector<std::vector<int>> answer;
    int x = 1000;
    int y = 1;
    while (x >= 1 && y <= 1000) {
      const int func_val = customfunction.f(x, y);
      if (func_val > z) {
        --x;
      } else if (func_val < z) {
        ++y;
      } else {
        answer.push_back(std::vector<int>{x, y});
        --x;
        ++y;
      }
    }
    return answer;
  }
};
