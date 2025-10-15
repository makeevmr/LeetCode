#include <vector>
#include <limits>

class Solution {
public:
  [[nodiscard]] static int maxScore(std::vector<std::vector<int>>& grid) {
    int max_score = std::numeric_limits<int>::min();
    const std::size_t rows = grid.size();
    const std::size_t columns = grid.front().size();
    for (std::size_t j = 1; j < columns; ++j) {
      max_score = std::max(max_score, grid[0][j] - grid[0][j - 1]);
      grid[0][j] = std::min(grid[0][j], grid[0][j - 1]);
    }
    for (std::size_t i = 1; i < rows; ++i) {
      max_score = std::max(max_score, grid[i][0] - grid[i - 1][0]);
      grid[i][0] = std::min(grid[i][0], grid[i - 1][0]);
    }
    for (std::size_t i = 1; i < rows; ++i) {
      for (std::size_t j = 1; j < columns; ++j) {
        const int min_adjacent = std::min(grid[i - 1][j], grid[i][j - 1]);
        max_score = std::max(max_score, grid[i][j] - min_adjacent);
        grid[i][j] = std::min(grid[i][j], min_adjacent);
      }
    }
    return max_score;
  }
};