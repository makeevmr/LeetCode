/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Time complexity: O(rows * columns)
Additional memory complexity: O(1)
Idea: use first row and first column to store zero flags if corresponding row or column must be
filled with zeros */

#include <iostream>
#include <vector>

class Solution {
public:
    static void setZeroes(std::vector<std::vector<int>> &matrix) {
        bool fill_first_row = false;
        bool fill_first_column = false;
        if (matrix[0][0] == 0) {
            fill_first_row = true;
            fill_first_column = true;
        }
        if (!fill_first_row) {
            for (std::size_t i = 1; i < matrix[0].size(); ++i) {
                if (matrix[0][i] == 0) {
                    fill_first_row = true;
                    break;
                }
            }
        }
        if (!fill_first_column) {
            for (std::size_t i = 1; i < matrix.size(); ++i) {
                if (matrix[i][0] == 0) {
                    fill_first_column = true;
                    break;
                }
            }
        }
        for (std::size_t i = 1; i < matrix.size(); ++i) {
            for (std::size_t j = 1; j < matrix.front().size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (std::size_t j = 1; j < matrix.front().size(); ++j) {
            if (matrix[0][j] == 0) {
                fillColumn(matrix, j);
            }
        }
        for (std::size_t i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                fillRow(matrix, i);
            }
        }
        if (fill_first_column) {
            fillColumn(matrix, 0);
        }
        if (fill_first_row) {
            fillRow(matrix, 0);
        }
    }

private:
    static void fillRow(std::vector<std::vector<int>> &matrix, std::size_t row) {
        for (std::size_t j = 0; j < matrix.front().size(); ++j) {
            matrix[row][j] = 0;
        }
    }

    static void fillColumn(std::vector<std::vector<int>> &matrix, std::size_t column) {
        for (std::size_t i = 0; i < matrix.size(); ++i) {
            matrix[i][column] = 0;
        }
    }
};

int main() {
    // std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution::setZeroes(matrix);
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        for (std::size_t j = 0; j < matrix.front().size(); ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}