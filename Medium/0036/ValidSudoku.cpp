/* Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according
to the following rules: */
// Time complexity solution: O(n ^ 2), where n is is of sudoku
// Additional memory complexity: O(n)
// Idea: check each row, column and square(3 x 3)

#include <iostream>
#include <vector>

class Solution {
public:
    static bool isValidSudoku(const std::vector<std::vector<char>> &board) {
        for (int row = 0; row < sudoku_size; ++row) {
            if (!isValidRow(board, row)) {
                return false;
            }
        }
        for (int column = 0; column < sudoku_size; ++column) {
            if (!isValidColumn(board, column)) {
                return false;
            }
        }
        for (int box_number = 0; box_number < sudoku_size; ++box_number) {
            if (!isValidBox(board, box_number)) {
                return false;
            }
        }
        return true;
    }

private:
    static const int sudoku_size = 9;

    static bool isValidRow(const std::vector<std::vector<char>> &board, const int row) {
        std::vector<bool> is_contains_number(10, false);
        for (int column = 0; column < sudoku_size; ++column) {
            if (board[row][column] == '.') {
                continue;
            }
            if (!checkNumber(board, is_contains_number, row, column)) {
                return false;
            }
        }
        return true;
    }

    static bool isValidColumn(const std::vector<std::vector<char>> &board, const int column) {
        std::vector<bool> is_contains_number(10, false);
        for (int row = 0; row < sudoku_size; ++row) {
            if (board[row][column] == '.') {
                continue;
            }
            if (!checkNumber(board, is_contains_number, row, column)) {
                return false;
            }
        }
        return true;
    }

    static bool isValidBox(const std::vector<std::vector<char>> &board, const int box_number) {
        int start_row = (box_number / 3) * 3;
        int start_column = (box_number % 3) * 3;
        int end_row = start_row + 3;
        int end_column = start_column + 3;
        std::vector<bool> is_contains_number(10, false);
        for (int row = start_row; row < end_row; ++row) {
            for (int column = start_column; column < end_column; ++column) {
                if (board[row][column] == '.') {
                    continue;
                }
                if (!checkNumber(board, is_contains_number, row, column)) {
                    return false;
                }
            }
        }
        return true;
    }

    static bool checkNumber(const std::vector<std::vector<char>> &board,
                            std::vector<bool> &is_contains_number, const int row,
                            const int column) {
        if (!is_contains_number[board[row][column] - '0']) {
            return is_contains_number[board[row][column] - '0'] = true;
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // std::vector<std::vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    //                                         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //                                         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //                                         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //                                         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //                                         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //                                         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //                                         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //                                         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << Solution::isValidSudoku(board) << '\n';
    return 0;
}
