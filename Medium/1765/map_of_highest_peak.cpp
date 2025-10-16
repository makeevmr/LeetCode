#include <vector>
#include <queue>

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<int>> highestPeak(
      const std::vector<std::vector<int>>& is_water) {
    const int rows = static_cast<int>(is_water.size());
    const int columns = static_cast<int>(is_water.front().size());
    std::vector<std::vector<int>> height(rows, std::vector(columns, -1));
    std::queue<Point> queue;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        if (is_water[i][j] == 1) {
          height[i][j] = 0;
          queue.push(Point{.row_ = i, .col_ = j});
        }
      }
    }
    int curr_distance = 0;
    while (!queue.empty()) {
      ++curr_distance;
      const std::size_t queue_size = queue.size();
      for (std::size_t i = 0; i < queue_size; ++i) {
        const Point point = queue.front();
        queue.pop();
        for (const Point& offset : kOffsets) {
          Point new_point = {point.row_ + offset.row_,
                             point.col_ + offset.col_};
          if (0 <= new_point.row_ && new_point.row_ < rows &&
              0 <= new_point.col_ && new_point.col_ < columns &&
              height[new_point.row_][new_point.col_] == -1) {
            height[new_point.row_][new_point.col_] = curr_distance;
            queue.push(std::move(new_point));
          }
        }
      }
    }
    return height;
  }

private:
  struct Point {
    int row_;
    int col_;
  };

  static constexpr Point kOffsets[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};