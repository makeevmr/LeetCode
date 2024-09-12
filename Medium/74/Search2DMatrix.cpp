/* You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
Time complexity: O(log(m * n))
Additional memory complexity: O(1)
Idea: use binary search two times (on rows, and then on columns)
*/

#include <vector>

class Solution {
public:
    [[nodiscard]] static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row_left = 0;
        int row_right = static_cast<int>(matrix.size());
        while (row_left < row_right - 1) {
            int row_middle = (row_left + row_right) >> 1;
            if (matrix[row_middle][0] > target) {
                row_right = row_middle;
            } else {
                row_left = row_middle;
            }
        }
        if (matrix[row_left].front() > target || target > matrix[row_left].back()) {
            return false;
        }
        int column_left = 0;
        int column_right = static_cast<int>(matrix.front().size());
        while (column_left < column_right - 1) {
            int column_middle = (column_left + column_right) >> 1;
            if (matrix[row_left][column_middle] > target) {
                column_right = column_middle;
            } else {
                column_left = column_middle;
            }
        }
        return matrix[row_left][column_left] == target;
    }
};
