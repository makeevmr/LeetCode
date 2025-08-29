/* Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above
it as shown: */

#include <vector>

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<int>> generate(
      const int& num_rows) {
    std::vector<std::vector<int>> pascal_triangle = {std::vector<int>{1}};
    for (int _ = 1; _ < num_rows; ++_) {
      std::vector<int> new_row = {1};
      for (std::size_t i = 0; i < pascal_triangle.back().size() - 1; ++i) {
        new_row.push_back(pascal_triangle.back()[i] +
                          pascal_triangle.back()[i + 1]);
      }
      new_row.push_back(1);
      pascal_triangle.push_back(std::move(new_row));
    }
    return pascal_triangle;
  }
};
