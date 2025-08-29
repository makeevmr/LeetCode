/* According to Wikipedia's article: "The Game of Life, also known simply as
   Life, is a cellular automaton devised by the British mathematician John
   Horton Conway in 1970. The next state is created by applying the above rules
   simultaneously to every cell in the current state, where births and deaths
   occur simultaneously. Given the current state of the m x n grid board, return
   the next state. */
// Time complexity: O(m * n), where m is number of rows, n is number of
// columns in board respectively
// Additional memory complexity: O(1)
// Idea: store new state (live/dead) in second bit of integer

#include <iostream>
#include <vector>

class Solution {
public:
  static void gameOfLife(std::vector<std::vector<int>>& board) {
    const int rows = static_cast<int>(board.size());
    const int columns = static_cast<int>(board.front().size());
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        board[i][j] |= (getNewState(board, i, j, rows, columns) << 1);
      }
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        board[i][j] >>= 1;
      }
    }
  }

private:
  static bool getNewState(const std::vector<std::vector<int>>& board,
                          const int& row, const int& column, const int& rows,
                          const int& columns) {
    short int live_neighbors = 0;
    for (int i = row - 1; i <= row + 1; ++i) {
      for (int j = column - 1; j <= column + 1; ++j) {
        if (i == row && j == column) {
          continue;
        }
        if (0 <= i && i < rows && 0 <= j && j < columns && (board[i][j] & 1)) {
          ++live_neighbors;
        }
      }
    }
    if (board[row][column]) {
      return (live_neighbors == 2 || live_neighbors == 3);
    } else {
      return live_neighbors == 3;
    }
  }
};

int main() {
  std::vector<std::vector<int>> board = {
      {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  Solution::gameOfLife(board);
  for (std::size_t i = 0; i < board.size(); ++i) {
    for (std::size_t j = 0; j < board.front().size(); ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}