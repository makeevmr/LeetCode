/* Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on
index i on the current row, you may move to either index i or index i + 1 on the next row.
Time complexity: O(triangle_size ^ 2)
Additional memory complexity: O(triangle_size)
Idea: compute min_paths on each step (min_paths[i] contains min sum on path from last_row to
current_row ended with triangle[current_row][i])
*/

#include <vector>

class Solution {
public:
    [[nodiscard]] static int minimumTotal(const std::vector<std::vector<int>>& triangle) {
        int triangle_width = static_cast<int>(triangle.size());
        // min_paths[i] contains min sum on path from last_row to current_row ended with
        std::vector<int> min_paths = triangle.back();
        for (int row = triangle_width - 2; row >= 0; --row) {
            for (int column = 0; column <= row; ++column) {
                min_paths[column] =
                    std::min(min_paths[column], min_paths[column + 1]) + triangle[row][column];
            }
        }
        return min_paths[0];
    }
};