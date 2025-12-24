#include <vector>
#include <queue>
#include <array>

struct Point {
  int row_;
  int col_;
};

Point operator+(const Point& left, const Point& right) noexcept {
  return Point{.row_ = left.row_ + right.row_, .col_ = left.col_ + right.col_};
}

class Solution {
public:
  static std::vector<std::vector<int>> colorBorder(
      std::vector<std::vector<int>>& grid, const int& row, const int& col,
      const int& color) {
    if (grid[row][col] == color) {
      return grid;
    }
    const int rows = static_cast<int>(grid.size());
    const int columns = static_cast<int>(grid.front().size());
    std::vector<Point> border_points;
    std::vector<std::vector<bool>> is_met_point(
        rows, std::vector<bool>(columns, false));
    std::queue<Point> points_queue;
    points_queue.push(Point{.row_ = row, .col_ = col});
    is_met_point[row][col] = true;
    while (!points_queue.empty()) {
      Point new_point = points_queue.front();
      points_queue.pop();
      for (const Point& offset : kOffsets) {
        Point adj_point = new_point + offset;
        if (0 <= adj_point.row_ && adj_point.row_ < rows &&
            0 <= adj_point.col_ && adj_point.col_ < columns &&
            !is_met_point[adj_point.row_][adj_point.col_] &&
            grid[adj_point.row_][adj_point.col_] == grid[row][col]) {
          is_met_point[adj_point.row_][adj_point.col_] = true;
          points_queue.push(adj_point);
        }
      }
      if (isBorderPoint(grid, rows, columns, new_point)) {
        border_points.push_back(std::move(new_point));
      }
    }
    for (const Point& border_point : border_points) {
      grid[border_point.row_][border_point.col_] = color;
    }
    return grid;
  }

private:
  static constexpr std::array<Point, 4> kOffsets = {Point{-1, 0}, Point{0, -1},
                                                    Point{1, 0}, Point{0, 1}};

  [[nodiscard]] static bool isBorderPoint(
      const std::vector<std::vector<int>> grid, const int& rows,
      const int& columns, const Point& point) {
    if (point.row_ == 0 || point.col_ == 0 || point.row_ == rows - 1 ||
        point.col_ == columns - 1) {
      return true;
    }
    for (const Point& offset : kOffsets) {
      Point adj_point = point + offset;
      if (grid[point.row_][point.col_] !=
          grid[adj_point.row_][adj_point.col_]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> grid = {{1, 1}, {1, 2}};
  int row = 0;
  int col = 0;
  int color = 3;
  Solution::colorBorder(grid, row, col, color);
  return 0;
}