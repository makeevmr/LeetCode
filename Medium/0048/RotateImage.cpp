/* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
(clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation. */
// Time complexity: O(n ^ 2), where n is size of matrix
// Additional memory complexity: O(1)
// Idea: for each cell we can figure out which 3 remaining cells it swaps with

#include <iostream>
#include <vector>

class Solution {
public:
    static void rotate(std::vector<std::vector<int>> &matrix) {
        int left_border = 0;
        int right_border = static_cast<int>(matrix.size()) - 1;
        int curr_row = 0;
        while (left_border < right_border) {
            for (int curr_column = left_border; curr_column < right_border; ++curr_column) {
                rotateCell(matrix, curr_row, curr_column);
            }
            ++left_border;
            --right_border;
            ++curr_row;
        }
    }

private:
    static void rotateCell(std::vector<std::vector<int>> &matrix, int row, int column) {
        int size = static_cast<int>(matrix.size());
        int buffer = matrix[row][column];
        std::swap(buffer, matrix[column][size - 1 - row]);
        std::swap(buffer, matrix[size - 1 - row][size - 1 - column]);
        std::swap(buffer, matrix[size - 1 - column][row]);
        std::swap(buffer, matrix[row][column]);
    }
};

int main() {
    // std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution::rotate(matrix);
    for (std::size_t row = 0; row < matrix.size(); ++row) {
        for (std::size_t column = 0; column < matrix[row].size(); ++column) {
            std::cout << matrix[row][column] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
