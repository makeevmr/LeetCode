#include <string>
#include <stack>

class Solution {
public:
  [[nodiscard]] static std::string convertToBase7(int num) {
    bool is_neg = false;
    if (num < 0) {
      is_neg = true;
      num *= -1;
    }
    std::stack<int> base7_stack;
    do {
      base7_stack.push(num % 7);
      num /= 7;
    } while (num != 0);
    std::string base7_str;
    if (is_neg) {
      base7_str.push_back('-');
    }
    while (!base7_stack.empty()) {
      base7_str.push_back('0' + base7_stack.top());
      base7_stack.pop();
    }
    return base7_str;
  }
};