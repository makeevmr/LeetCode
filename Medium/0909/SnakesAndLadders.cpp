/* You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a
Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and
alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6
destinations, regardless of the size of the board. If next has a snake or ladder, you must move to
the destination of that snake or ladder. Otherwise, you move to next. The game ends when you reach
the square n2. A board square on row r and column c has a snake or ladder if board[r][c] != -1. The
destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of
any snake or ladder.

Return the least number of moves required to reach the square n2. If it is not possible to reach the
square, return -1. */

#include <limits>
#include <vector>
#include <queue>
#include <iostream>

class Solution {
public:
    static int snakesAndLadders(std::vector<std::vector<int>> &board) {
        int board_size = static_cast<int>(board.size());
        std::vector<std::vector<std::pair<bool, bool>>> visited_squares(
            board_size, std::vector<std::pair<bool, bool>>(board_size, {false, false}));
        return BFS(board, visited_squares);
    }

private:
    static std::pair<int, int> getSquarePos(int board_size, int ind) {
        int row = board_size - 1 - (ind - 1) / board_size;
        int column = ind - (board_size - 1 - row) * board_size - 1;
        if ((board_size - 1 - row) % 2 != 0) {
            column = board_size - 1 - column;
        }
        return std::pair<int, int>{row, column};
    }

    // return least number of moves to reach n^2 square
    static int BFS(std::vector<std::vector<int>> &board,
                   std::vector<std::vector<std::pair<bool, bool>>> &visited_squares) {
        int board_size = static_cast<int>(board.size());
        int max_ind = board_size * board_size;
        int curr_moves = 0;
        std::queue<int> queue;
        queue.push(1);
        while (!queue.empty()) {
            ++curr_moves;
            std::size_t queue_size = queue.size();
            for (std::size_t i = 0; i < queue_size; ++i) {
                int curr_ind = queue.front();
                queue.pop();
                for (int new_ind = curr_ind + 1, max_turn_ind = std::min(curr_ind + 6, max_ind);
                     new_ind <= max_turn_ind; ++new_ind) {
                    std::pair<int, int> dest1_coord = getSquarePos(board_size, new_ind);
                    if (!visited_squares[dest1_coord.first][dest1_coord.second].first) {
                        int dest_ind = new_ind;
                        std::pair<int, int> dest2_coord = dest1_coord;
                        if (board[dest1_coord.first][dest1_coord.second] != -1) {
                            dest_ind = board[dest1_coord.first][dest1_coord.second];
                            dest2_coord = getSquarePos(board_size, dest_ind);
                        }
                        if (dest_ind == max_ind) {
                            return curr_moves;
                        }
                        bool dest_with_transition =
                            board[dest2_coord.first][dest2_coord.second] != -1;
                        bool single_transition = dest1_coord == dest2_coord;
                        if ((!dest_with_transition &&
                             !visited_squares[dest2_coord.first][dest2_coord.second].first &&
                             !visited_squares[dest2_coord.first][dest2_coord.second].second) ||
                            (dest_with_transition &&
                             ((single_transition &&
                               !visited_squares[dest1_coord.first][dest1_coord.second].first) ||
                              (!single_transition &&
                               !visited_squares[dest2_coord.first][dest2_coord.second].second)))) {
                            queue.push(dest_ind);
                        }
                        visited_squares[dest1_coord.first][dest1_coord.second].first = true;
                        visited_squares[dest2_coord.first][dest2_coord.second].second = true;
                    }
                }
            }
        }
        return -1;
    }
};
