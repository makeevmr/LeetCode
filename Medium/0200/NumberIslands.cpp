/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands. An island is surrounded by water and
is formed by connecting adjacent lands horizontally or vertically. You may
assume all four edges of the grid are all surrounded by water.
*/

#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static int numIslands(std::vector<std::vector<char>>& grid) {
    int rows = static_cast<int>(grid.size());
    int columns = static_cast<int>(grid.front().size());
    int islands = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < columns; ++col) {
        if (grid[row][col] == '1') {
          DFS(grid, row, col);
          ++islands;
        }
      }
    }
    return islands;
  }

private:
  static void DFS(std::vector<std::vector<char>>& grid, int row, int col) {
    if ((row < 0) || (col < 0) || (row == static_cast<int>(grid.size())) ||
        (col == static_cast<int>(grid.front().size())) ||
        (grid[row][col] == '0') || (grid[row][col] == '#')) {
      return;
    }
    grid[row][col] = '#';
    DFS(grid, row + 1, col);
    DFS(grid, row, col + 1);
    DFS(grid, row - 1, col);
    DFS(grid, row, col - 1);
  }
};
