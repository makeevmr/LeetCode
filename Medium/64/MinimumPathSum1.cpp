/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Time complexity: O(rows * columns)
Additional memory complexity: O(rows)
Idea: use dynamic programming approach (row_sum[i] stores min path sum from grid[0][0] to
grid[curr_row][i])
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int minPathSum(const std::vector<std::vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int columns = static_cast<int>(grid.front().size());
        std::vector<int> row_sum(columns);
        row_sum[0] = grid[0][0];
        for (int j = 1; j < columns; ++j) {
            row_sum[j] = grid[0][j] + row_sum[j - 1];
        }
        for (int row = 1; row < rows; ++row) {
            row_sum[0] += grid[row][0];
            for (int column = 1; column < columns; ++column) {
                row_sum[column] =
                    std::min(row_sum[column - 1], row_sum[column]) + grid[row][column];
            }
        }
        return row_sum.back();
    }
};