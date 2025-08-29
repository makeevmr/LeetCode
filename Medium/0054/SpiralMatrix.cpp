// Given an m x n matrix, return all elements of the matrix in spiral order.
// Time complexity: O(rows * columns)
// Additional memory complexity: O(1)
// Idea: iterate through matrix in right order

#include <iostream>
#include <vector>

class Solution {
public:
  static std::vector<int> spiralOrder(
      const std::vector<std::vector<int>>& matrix) {
    int rows = static_cast<int>(matrix.size());
    int columns = static_cast<int>(matrix.front().size());
    int decrement = 0;
    int curr_row = 0;
    int curr_column = -1;
    int direction = 0;
    int steps_in_direction = columns;
    std::vector<int> spiral_array(rows * columns);
    int spiral_array_index = 0;
    for (int i = 0; i < rows * columns; ++i) {
      if (steps_in_direction == 0) {
        switch (direction) {
          case 0:
            ++decrement;
            steps_in_direction = rows - decrement;
            break;
          case 1:
            steps_in_direction = columns - decrement;
            break;
          case 2:
            ++decrement;
            steps_in_direction = rows - decrement;
            break;
          case 3:
            steps_in_direction = columns - decrement;
            break;
        }
        direction = (direction + 1) % 4;
      }
      switch (direction) {
        case 0:
          ++curr_column;
          break;
        case 1:
          ++curr_row;
          break;
        case 2:
          --curr_column;
          break;
        case 3:
          --curr_row;
          break;
      }
      spiral_array[spiral_array_index++] = matrix[curr_row][curr_column];
      --steps_in_direction;
    }
    return spiral_array;
  }
};

int main() {
  // std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> spiral_array = Solution::spiralOrder(matrix);
  for (const auto& number : spiral_array) {
    std::cout << number << ' ';
  }
  std::cout << '\n';
  return 0;
}