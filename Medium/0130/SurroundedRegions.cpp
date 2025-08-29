/* You are given an m x n matrix board containing letters 'X' and 'O', capture
regions that are surrounded: Connect: A cell is connected to adjacent cells
horizontally or vertically. Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region
with 'X' cells and none of the region cells are on the edge of the board. A
surrounded region is captured by replacing all 'O's with 'X's in the input
matrix board. Time complexity: O(rows * columns) Memory complexity: O(rows *
columns) Idea: use DFS algorithm
*/

#include <vector>
#include <iostream>

class Solution {
public:
  static void solve(std::vector<std::vector<char>>& board) {
    int rows = static_cast<int>(board.size());
    int columns = static_cast<int>(board.front().size());
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        if (board[row][column] == 'O') {
          bool is_surrounded = true;
          isSurroundedRegion(board, row, column, rows, columns, is_surrounded);
          if (is_surrounded) {
            paintOver(board, row, column, rows, columns, 'X');
          }
        }
      }
    }
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        if (board[row][column] == '#') {
          paintOver(board, row, column, rows, columns, 'O');
        }
      }
    }
  }

private:
  static void isSurroundedRegion(std::vector<std::vector<char>>& board, int row,
                                 int column, const int& rows,
                                 const int& columns, bool& is_surrounded) {
    if (row < 0 || column < 0 || row == rows || column == columns ||
        board[row][column] == 'X' || board[row][column] == '#') {
      return;
    }
    if (row == 0 || column == 0 || row == (rows - 1) ||
        column == (columns - 1)) {
      is_surrounded = false;
    }
    board[row][column] = '#';
    isSurroundedRegion(board, row - 1, column, rows, columns, is_surrounded);
    isSurroundedRegion(board, row, column - 1, rows, columns, is_surrounded);
    isSurroundedRegion(board, row + 1, column, rows, columns, is_surrounded);
    isSurroundedRegion(board, row, column + 1, rows, columns, is_surrounded);
  }

  static void paintOver(std::vector<std::vector<char>>& board, int row,
                        int column, const int& rows, const int& columns,
                        const char& color) {
    if (row < 0 || column < 0 || row == rows || column == columns ||
        board[row][column] == color || board[row][column] == 'X') {
      return;
    }
    board[row][column] = color;
    paintOver(board, row - 1, column, rows, columns, color);
    paintOver(board, row, column - 1, rows, columns, color);
    paintOver(board, row + 1, column, rows, columns, color);
    paintOver(board, row, column + 1, rows, columns, color);
  }
};

int main() {
  std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'},
                                          {'X', 'O', 'O', 'X'},
                                          {'X', 'X', 'O', 'X'},
                                          {'X', 'O', 'X', 'X'}};
  Solution::solve(board);
  for (std::size_t i = 0; i < board.size(); ++i) {
    for (std::size_t j = 0; j < board.front().size(); ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
