#include <optional>
#include <deque>
#include <string>
#include <cctype>

class Solution {
public:
  [[nodiscard]] static int calculate(const std::string& s) {
    std::size_t i = 0;
    int minus_counter = 0;
    std::deque<ExpressionNode> expression;
    const std::size_t s_size = s.size();
    while (i < s_size) {
      if (s[i] == ' ') {
        while (i < s_size && s[i] == ' ') {
          ++i;
        }
        continue;
      }
      if (std::isdigit(s[i]) != 0) {
        int new_num = 0;
        while (i < s_size && std::isdigit(s[i]) != 0) {
          new_num = new_num * 10 + (s[i] - '0');
          ++i;
        }
        if (expression.empty() || expression.back().oper_.has_value()) {
          if (minus_counter % 2 == 1) {
            new_num *= -1;
          }
          if (expression.empty()) {
            expression.emplace_back(std::nullopt, new_num);
            minus_counter = 0;
            continue;
          }
          const char top_oper = expression.back().oper_.value();
          if (top_oper == '*' || top_oper == '/') {
            expression.pop_back();
            const int left = expression.back().number_.value();
            expression.pop_back();
            expression.emplace_back(std::nullopt, top_oper == '*'
                                                      ? left * new_num
                                                      : left / new_num);
          } else {
            expression.emplace_back(std::nullopt, new_num);
          }
        } else {
          expression.emplace_back(minus_counter % 2 == 1 ? '-' : '+',
                                  std::nullopt);
          expression.emplace_back(std::nullopt, new_num);
        }
        minus_counter = 0;
        continue;
      }
      if (s[i] == '-') {
        ++minus_counter;
      } else if (s[i] == '*' || s[i] == '/') {
        expression.emplace_back(s[i], std::nullopt);
      }
      ++i;
    }
    while (expression.size() > 1) {
      const int left = expression.front().number_.value();
      expression.pop_front();
      const char oper = expression.front().oper_.value();
      expression.pop_front();
      const int right = expression.front().number_.value();
      expression.pop_front();
      expression.emplace_front(std::nullopt,
                               oper == '+' ? left + right : left - right);
    }
    return expression.front().number_.value();
  }

private:
  struct ExpressionNode {
    ExpressionNode(const std::optional<char>& oper,
                   const std::optional<int>& number)
        : oper_(oper),
          number_(number) {}

    std::optional<char> oper_;
    std::optional<int> number_;
  };
};