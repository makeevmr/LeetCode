/* Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More
formally, if you are on index i on the current row, you may move to either index
i or index i + 1 on the next row. Time complexity: O(triangle_size ^ 2)
Additional memory complexity: O(triangle_size)
Idea: compute min_paths on each step (min_paths[i] contains min sum on path
ended with triangle[current_row][i])
*/

#include <vector>

class Solution {
public:
  [[nodiscard]] static int minimumTotal(
      const std::vector<std::vector<int>>& triangle) {
    int triangle_width = static_cast<int>(triangle.size());
    // min_paths[i] contains min sum on path ended with triangle[current_row][i]
    std::vector<int> min_paths(triangle_width, 0);
    for (int row = 0; row < triangle_width; ++row) {
      int row_size = row + 1;
      std::vector<int> tmp_min_paths(triangle_width, 0);
      tmp_min_paths[0] = min_paths[0] + triangle[row][0];
      for (int column = 1; column < row_size; ++column) {
        if (column < row) {
          tmp_min_paths[column] =
              triangle[row][column] +
              std::min(min_paths[column - 1], min_paths[column]);
        } else {
          tmp_min_paths[column] = triangle[row][column] + min_paths[column - 1];
        }
      }
      min_paths = std::move(tmp_min_paths);
    }
    int answer = min_paths[0];
    for (const auto& path_sum : min_paths) {
      answer = std::min(answer, path_sum);
    }
    return answer;
  }
};
