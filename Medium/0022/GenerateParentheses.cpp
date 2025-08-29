#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> generateParenthesis(int n) {
    std::string curr_paren(2 * n, 0);
    std::vector<std::string> answer = {};
    generator(n, 0, 0, answer, curr_paren);
    return answer;
  }

private:
  static void generator(int n, int open_paren, int close_paren,
                        std::vector<std::string>& answer,
                        std::string& curr_paren) {
    if ((open_paren + close_paren) == 2 * n) {
      answer.push_back(curr_paren);
      return;
    }
    if (open_paren < n) {
      curr_paren[open_paren + close_paren] = '(';
      generator(n, open_paren + 1, close_paren, answer, curr_paren);
    }
    if (close_paren < open_paren) {
      curr_paren[open_paren + close_paren] = ')';
      generator(n, open_paren, close_paren + 1, answer, curr_paren);
    }
  }
};

int main() {
  std::vector<std::string> answer = Solution::generateParenthesis(1);
  for (std::size_t i = 0; i < answer.size(); ++i) {
    std::cout << answer[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
