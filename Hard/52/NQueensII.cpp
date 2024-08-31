/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two
queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Time complexity: O(n!)
Additional memory complexity: O(n)
Idea: use permutation of numbers 0...(n - 1) to represent queens placement (index of number is
column, number itself is row), use array of main_diad, secondary_diag to represent engaged diagonals
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int totalNQueens(int n) {
        std::vector<int> curr_permutation(n);
        for (int i = 0; i < n; ++i) {
            curr_permutation[i] = i;
        }
        std::vector<bool> main_diag(2 * n - 1, false);
        std::vector<bool> secondary_diag(2 * n - 1, false);
        int arrangemet_number = 0;
        getNumberArrangements(curr_permutation, main_diag, secondary_diag, n, arrangemet_number, 0);
        return arrangemet_number;
    }

private:
    static void getNumberArrangements(std::vector<int>& curr_permutation,
                                      std::vector<bool>& main_diag,
                                      std::vector<bool>& secondary_diag, const int& board_size,
                                      int& arrangemet_number, int level) {
        if (level == board_size) {
            ++arrangemet_number;
            return;
        }
        for (int i = level; i < board_size; ++i) {
            if (!main_diag[curr_permutation[i] - level + board_size - 1] &&
                !secondary_diag[curr_permutation[i] + level]) {
                main_diag[curr_permutation[i] - level + board_size - 1] = true;
                secondary_diag[curr_permutation[i] + level] = true;
                std::swap(curr_permutation[level], curr_permutation[i]);
                getNumberArrangements(curr_permutation, main_diag, secondary_diag, board_size,
                                      arrangemet_number, level + 1);
                std::swap(curr_permutation[level], curr_permutation[i]);
                secondary_diag[curr_permutation[i] + level] = false;
                main_diag[curr_permutation[i] - level + board_size - 1] = false;
            }
        }
    }
};

int main() {
    std::cout << Solution::totalNQueens(4) << '\n';
    std::cout << Solution::totalNQueens(1) << '\n';
    return 0;
}
