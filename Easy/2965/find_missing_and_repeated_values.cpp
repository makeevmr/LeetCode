#include <vector>
#include <unordered_set>

class Solution {
public:
  [[nodiscard]] static std::vector<int> findMissingAndRepeatedValues(
      const std::vector<std::vector<int>>& grid) {
    const std::size_t rows = grid.size();
    const std::size_t columns = grid.front().size();
    std::unordered_set<int> grid_nums;
    std::vector<int> answer(2);
    for (std::size_t i = 0; i < rows; ++i) {
      for (std::size_t j = 0; j < columns; ++j) {
        if (grid_nums.contains(grid[i][j])) {
          answer[0] = grid[i][j];
        }
        grid_nums.insert(grid[i][j]);
      }
    }
    for (int i = 1; i <= static_cast<int>(rows * rows); ++i) {
      if (!grid_nums.contains(i)) {
        answer[1] = i;
      }
    }
    return answer;
  }
};
