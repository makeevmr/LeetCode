#include <vector>
#include <string>
#include <cstdint>

class Solution {
public:
  [[nodiscard]] static int countCells(
      const std::vector<std::vector<char>>& grid, const std::string& pattern) {
    std::vector<std::vector<std::uint8_t>> marked_grid(
        grid.size(), std::vector<std::uint8_t>(grid.front().size(), 0));
    int answer = 0;
    findOccurrences(grid, pattern, marked_grid, answer);
    findOccurrences(grid, pattern, marked_grid, answer, false);
    return answer;
  }

private:
  [[nodiscard]] static std::vector<std::size_t> prefixFunction(
      const std::string& s) {
    const std::size_t s_size = s.size();
    std::vector<std::size_t> pref_func(s_size);
    for (std::size_t i = 1; i < s_size; ++i) {
      std::size_t j = pref_func[i - 1];
      while (j > 0 && s[i] != s[j]) {
        j = pref_func[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      pref_func[i] = j;
    }
    return pref_func;
  }

  static void calcMatchLen(const std::vector<std::vector<char>>& grid,
                           const std::string& substr,
                           const std::vector<std::size_t>& pref_func,
                           const std::size_t& row, const std::size_t& column,
                           std::size_t& match_len) {
    while (match_len > 0 && grid[row][column] != substr[match_len]) {
      match_len = pref_func[match_len - 1];
    }
    if (grid[row][column] == substr[match_len]) {
      ++match_len;
    }
  }

  static void findOccurrences(
      const std::vector<std::vector<char>>& grid, const std::string& substr,
      std::vector<std::vector<std::uint8_t>>& marked_grid, int& answer,
      bool by_rows = true) {
    const std::size_t rows = grid.size();
    const std::size_t columns = grid.front().size();
    const std::size_t substr_size = substr.size();
    const std::vector<std::size_t> pref_func = prefixFunction(substr);
    std::size_t match_len = 0;
    if (by_rows) {
      for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t column = 0; column < columns; ++column) {
          calcMatchLen(grid, substr, pref_func, row, column, match_len);
          if (match_len == substr_size) {
            int to_mark = match_len;
            int row_to_mark = row;
            int column_to_mark = column;
            while (to_mark > 0 &&
                   marked_grid[row_to_mark][column_to_mark] == 0) {
              ++marked_grid[row_to_mark][column_to_mark];
              --to_mark;
              --column_to_mark;
              if (column_to_mark < 0) {
                --row_to_mark;
                column_to_mark = columns - 1;
              }
            }
            match_len = pref_func[match_len - 1];
          }
        }
      }
    } else {
      for (std::size_t column = 0; column < columns; ++column) {
        for (std::size_t row = 0; row < rows; ++row) {
          calcMatchLen(grid, substr, pref_func, row, column, match_len);
          if (match_len == substr_size) {
            int to_mark = match_len;
            int row_to_mark = row;
            int column_to_mark = column;
            while (to_mark > 0 &&
                   marked_grid[row_to_mark][column_to_mark] < 2) {
              if (marked_grid[row_to_mark][column_to_mark] == 1) {
                ++answer;
                marked_grid[row_to_mark][column_to_mark] = 2;
              }
              --to_mark;
              --row_to_mark;
              if (row_to_mark < 0) {
                --column_to_mark;
                row_to_mark = rows - 1;
              }
            }
            match_len = pref_func[match_len - 1];
          }
        }
      }
    }
  }
};