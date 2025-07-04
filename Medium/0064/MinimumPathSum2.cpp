/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Time complexity: O(rows * columns)
Additional memory complexity: O(rows * columns)
Idea: use dynamic programming approach (grid_sum[i][j] stores min path sum from grid[0][0] to
grid[i][j])
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int minPathSum(const std::vector<std::vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int columns = static_cast<int>(grid.front().size());
        std::vector<std::vector<int>> grid_sum(rows, std::vector<int>(columns));
        grid_sum[0][0] = grid[0][0];
        for (int i = 1; i < rows; ++i) {
            grid_sum[i][0] = grid[i][0] + grid_sum[i - 1][0];
        }
        for (int j = 1; j < columns; ++j) {
            grid_sum[0][j] = grid[0][j] + grid_sum[0][j - 1];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                grid_sum[i][j] = grid[i][j] + std::min(grid_sum[i][j - 1], grid_sum[i - 1][j]);
            }
        }
        return grid_sum[rows - 1][columns - 1];
    }
};