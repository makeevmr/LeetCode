/* You are given an m x n integer array grid. There is a robot initially located
at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 *
109. Time complexity: O(rows * columns) Additional memory complexity: O(columns)
Idea: use dynamic programming approach (unique_paths[column] store unique_paths
from (0, 0) to (curr_row, column) on each row)
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int uniquePathsWithObstacles(
      const std::vector<std::vector<int>>& obstacle_grid) {
    int rows = static_cast<int>(obstacle_grid.size());
    int columns = static_cast<int>(obstacle_grid.front().size());
    std::vector<int> unique_paths;
    unique_paths.reserve(columns);
    unique_paths.push_back((obstacle_grid[0][0] == 1) ? 0 : 1);
    for (int column = 1; column < columns; ++column) {
      unique_paths.push_back(
          (obstacle_grid[0][column] == 1) ? 0 : unique_paths[column - 1]);
    }
    for (int row = 1; row < rows; ++row) {
      if (obstacle_grid[row][0] == 1) {
        unique_paths[0] = 0;
      }
      for (int column = 1; column < columns; ++column) {
        if (obstacle_grid[row][column] == 1) {
          unique_paths[column] = 0;
        } else {
          unique_paths[column] += unique_paths[column - 1];
        }
      }
    }
    return unique_paths.back();
  }
};