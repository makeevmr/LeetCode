#include <limits>
#include <vector>

class Solution {
public:
  [[nodiscard]] static int countCoveredBuildings(
      int n, const std::vector<std::vector<int>>& buildings) {
    std::vector<Range> x_ranges(n + 1);
    std::vector<Range> y_ranges(n + 1);
    for (const auto& dot : buildings) {
      x_ranges[dot[1]].min_val_ = std::min(x_ranges[dot[1]].min_val_, dot[0]);
      x_ranges[dot[1]].max_val_ = std::max(x_ranges[dot[1]].max_val_, dot[0]);
      y_ranges[dot[0]].min_val_ = std::min(y_ranges[dot[0]].min_val_, dot[1]);
      y_ranges[dot[0]].max_val_ = std::max(y_ranges[dot[0]].max_val_, dot[1]);
    }
    int covered_dots = 0;
    for (const auto& dot : buildings) {
      if ((x_ranges[dot[1]].min_val_ < dot[0]) &&
          (dot[0] < x_ranges[dot[1]].max_val_) &&
          (y_ranges[dot[0]].min_val_ < dot[1]) &&
          (dot[1] < y_ranges[dot[0]].max_val_)) {
        ++covered_dots;
      }
    }
    return covered_dots;
  }

private:
  struct Range {
    int min_val_ = std::numeric_limits<int>::max();
    int max_val_ = std::numeric_limits<int>::min();
  };
};