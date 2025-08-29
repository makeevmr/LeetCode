/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You
may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space,
respectively.

Time complexity: O(n!)
Additional memory complexity: O(n)
Idea: permutations generation technique
for (int i = left; i < size; ++i) {
    std::swap(curr_order[left], curr_order[i]);
    permutations(answer, left + 1, size);
    std::swap(curr_order[left], curr_order[i]);
}
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<std::string>> solveNQueens(
      int n) {
    std::vector<std::vector<std::string>> answer;
    permutations(answer, 0, n);
    return answer;
  }

  static void permutations(std::vector<std::vector<std::string>>& answer,
                           int left, const int size) {
    if (left == size) {
      answer.push_back(std::vector<std::string>(size));
      for (int column = 0; column < size; ++column) {
        for (int row = 0; row < size; ++row) {
          if (curr_order[column] == row) {
            answer.back()[row] += "Q";
          } else {
            answer.back()[row] += ".";
          }
        }
      }
    }

    for (int i = left; i < size; ++i) {
      if (!main_diags.contains(curr_order[i] - left) &&
          !sub_diags.contains(curr_order[i] + left)) {
        main_diags.insert(curr_order[i] - left);
        sub_diags.insert(curr_order[i] + left);
        std::swap(curr_order[left], curr_order[i]);
        permutations(answer, left + 1, size);
        std::swap(curr_order[left], curr_order[i]);
        main_diags.erase(curr_order[i] - left);
        sub_diags.erase(curr_order[i] + left);
      }
    }
  }

private:
  static std::vector<int> curr_order;
  static std::unordered_set<int> main_diags;
  static std::unordered_set<int> sub_diags;
};

std::vector<int> Solution::curr_order = {0, 1, 2, 3, 4, 5, 6, 7, 8};
std::unordered_set<int> Solution::main_diags = {};
std::unordered_set<int> Solution::sub_diags = {};

int main() {
  std::vector<std::vector<std::string>> answer = Solution::solveNQueens(5);
  for (const auto& board : answer) {
    for (const auto& row : board) {
      std::cout << row << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}