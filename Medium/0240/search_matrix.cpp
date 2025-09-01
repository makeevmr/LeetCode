#include <vector>

class Solution {
public:
  [[nodiscard]] static bool searchMatrix(
      const std::vector<std::vector<int>>& matrix, int target) {
    int rows = static_cast<int>(matrix.size());
    int columns = static_cast<int>(matrix[0].size());
    int row = 0;
    int col = columns - 1;
    while (row < rows && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      }
      if (matrix[row][col] < target) {
        ++row;
      } else {
        --col;
      }
    }
    return false;
  }
};