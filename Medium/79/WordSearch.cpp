/* Given an m x n grid of characters board and a string word, return true if word exists in the
grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once.
Time complexity: O(rows * columns * 3 ^ (word_size - 1))
Additional memory complexity: O(word_size)
Idea: use DFS to consider all possible ways in graph, store met cells in board
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    [[nodiscard]] static bool exist(std::vector<std::vector<char>>& board,
                                    const std::string& word) {
        int rows = static_cast<int>(board.size());
        int columns = static_cast<int>(board.front().size());
        int word_size = static_cast<int>(word.size());
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (DFS(board, word, rows, columns, word_size, row, column, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    [[nodiscard]] static bool DFS(std::vector<std::vector<char>>& board, const std::string& word,
                                  const int& rows, const int& columns, const int& word_size,
                                  int row, int column, int word_ind) {
        if (board[row][column] != word[word_ind]) {
            return false;
        }
        if (word_ind == word_size - 1) {
            return true;
        }
        board[row][column] = '#';
        for (int i = 0; i < 4; ++i) {
            int new_row = row + offsets[i].first;
            int new_column = column + offsets[i].second;
            if ((0 <= new_row && new_row < rows) && (0 <= new_column && new_column < columns) &&
                board[new_row][new_column] != '#' &&
                DFS(board, word, rows, columns, word_size, new_row, new_column, word_ind + 1)) {
                return true;
            }
        }
        board[row][column] = word[word_ind];
        return false;
    }

    static constexpr const std::pair<int, int> offsets[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

int main() {
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";
    // std::vector<std::vector<char>> board = {
    //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // std::string word = "SEE";
    // std::vector<std::vector<char>> board = {
    //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // std::string word = "ABCD";
    std::cout << Solution::exist(board, word) << '\n';
    return 0;
}
