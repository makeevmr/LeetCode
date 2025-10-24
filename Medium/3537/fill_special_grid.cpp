#include <vector>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<int>> specialGrid(const int n) {
    const std::uint64_t grid_size = (1ULL << n);
    std::vector<std::vector<int>> grid(grid_size,
                                       std::vector<int>(grid_size, -1));
    fillGrid(grid, grid_size * grid_size, 0ULL, 0ULL, 0ULL, grid_size - 1,
             grid_size - 1);
    return grid;
  }

private:
  static void fillGrid(std::vector<std::vector<int>>& grid,
                       const std::uint64_t& to_fill,
                       const std::uint64_t& start_num,
                       const std::uint64_t& row_up,
                       const std::uint64_t& column_left,
                       const std::uint64_t& row_bottom,
                       const std::uint64_t& column_right) {
    if (to_fill == 1) {
      grid[row_up][column_left] = start_num;
      return;
    }
    const std::uint64_t quadrant_to_fill = to_fill / 4;
    const std::uint64_t row_split = row_up + (row_bottom - row_up + 1) / 2;
    const std::uint64_t column_split =
        column_left + (column_right - column_left + 1) / 2;
    fillGrid(grid, quadrant_to_fill, start_num, row_up, column_split,
             row_split - 1, column_right);
    fillGrid(grid, quadrant_to_fill, start_num + quadrant_to_fill, row_split,
             column_split, row_bottom, column_right);
    fillGrid(grid, quadrant_to_fill, start_num + quadrant_to_fill * 2,
             row_split, column_left, row_bottom, column_split - 1);
    fillGrid(grid, quadrant_to_fill, start_num + quadrant_to_fill * 3, row_up,
             column_left, row_split - 1, column_split - 1);
  }
};