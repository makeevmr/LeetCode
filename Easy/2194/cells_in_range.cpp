#include <vector>
#include <string>

class Solution {
public:
  [[nodiscard]] static std::vector<std::string> cellsInRange(
      const std::string& s) {
    std::vector<std::string> answer;
    for (char col = s[0]; col <= s[3]; ++col) {
      for (char row = s[1]; row <= s[4]; ++row) {
        answer.push_back(std::string(1, col) + std::string(1, row));
      }
    }
    return answer;
  }
};