/* Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's
and return its area.
Time complexity: O(rows * columns)
Additional memory complexity: O(columns)
Idea: dp[i][j] is square size with bottom right corner in i j position
dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix.front().size());
        std::vector<int> square_size(columns, 0);
        int max_area = 0;
        for (int column = 0; column < columns; ++column) {
            if (matrix[0][column] == '1') {
                square_size[column] = 1;
            }
            max_area = std::max(max_area, square_size[column]);
        }
        for (int row = 1; row < rows; ++row) {
            int prev_diag = square_size[0];
            if (matrix[row][0] == '1') {
                square_size[0] = 1;
            }
            max_area = std::max(max_area, square_size[0]);
            for (int column = 1; column < columns; ++column) {
                if (matrix[row][column] == '1') {
                    int& curr_area = square_size[column];
                    curr_area = std::min(std::min(square_size[column - 1], square_size[column]),
                                         prev_diag) +
                                1;
                    max_area = std::max(max_area, curr_area * curr_area);
                }
                prev_diag = square_size[column];
            }
        }
        return max_area;
    }
};

int main() {
    std::vector<std::vector<char>> matrix = {{'1', '1', '1', '1', '0'},
                                             {'1', '1', '1', '1', '0'},
                                             {'1', '1', '1', '1', '1'},
                                             {'1', '1', '1', '1', '1'},
                                             {'0', '0', '1', '1', '1'}};
    std::cout << Solution::maximalSquare(matrix) << '\n';
    return 0;
}