// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility) P   A   H   N A P L S I I G Y   I   R Time complexity:
// O(n) Additional memory complexity: O(1) Idea: calculate result row by row

#include <iostream>
#include <string>

class Solution {
public:
  static std::string convert(const std::string& s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    std::string converted_string;
    int s_size = static_cast<int>(s.size());
    int base_addition = 2 * numRows - 2;
    int out_index = 0;
    while (out_index < s_size) {
      converted_string.push_back(s[out_index]);
      out_index += base_addition;
    }
    for (int curr_row = 1; curr_row < numRows - 1; ++curr_row) {
      if (curr_row < s_size) {
        converted_string.push_back(s[curr_row]);
      } else {
        break;
      }
      int diagonal_index = base_addition - curr_row;
      int column_index = base_addition + curr_row;
      while (diagonal_index < s_size) {
        converted_string.push_back(s[diagonal_index]);
        if (column_index < s_size) {
          converted_string.push_back(s[column_index]);
        }
        diagonal_index += base_addition;
        column_index += base_addition;
      }
    }
    int last_row_index = numRows - 1;
    while (last_row_index < s_size) {
      converted_string.push_back(s[last_row_index]);
      last_row_index += base_addition;
    }
    return converted_string;
  }
};

int main() {
  // std::string s = "PAYPALISHIRING";
  // int numRows = 3;
  // std::cout << Solution::convert(s, numRows) << '\n';
  // std::string s = "PAYPALISHIRING";
  // int numRows = 4;
  // std::cout << Solution::convert(s, numRows) << '\n';
  std::string s = "A";
  int numRows = 1;
  std::cout << Solution::convert(s, numRows) << '\n';
  return 0;
}
