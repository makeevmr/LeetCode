#include <iostream>
#include <vector>

class Solution {
public:
  static int numberOfAlternatingGroups(const std::vector<int>& colors) {
    int counter = 0;
    for (std::size_t i = 0; i < colors.size(); ++i) {
      if (isAlternating(colors, i)) {
        ++counter;
      }
    }
    return counter;
  }

private:
  static bool isAlternating(const std::vector<int>& colors, std::size_t index) {
    return colors[index] == colors[(index + 2) % colors.size()] &&
           colors[index] != colors[(index + 1) % colors.size()];
  }
};

int main() {
  std::vector<int> colors = {0, 1, 0, 0, 1};
  std::cout << Solution::numberOfAlternatingGroups(colors) << '\n';
  return 0;
}
