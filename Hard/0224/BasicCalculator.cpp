/* Given a string s representing a valid expression, implement a basic
calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings
as mathematical expressions, such as eval(). 1 <= s.length <= 3 * 105 s consists
of digits, '+', '-', '(', ')', and ' '. s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
Time complexity: O(n), where n is size of string
Additional memory complexity: O(n)
Idea: use stacks to store calculated values and operations
*/

#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
  static int calculate(const std::string& s) {
    std::stack<Operator> operations;
    std::stack<int> values;
    int curr_value = 0;
    bool is_curr_value_empty = true;
    bool is_start_of_scope = true;
    for (const char& symbol : s) {
      if ('0' <= symbol && symbol <= '9') {
        curr_value = curr_value * 10 + (symbol - '0');
        is_start_of_scope = false;
        is_curr_value_empty = false;
      } else {
        if (!is_curr_value_empty) {
          pushValue(operations, values, curr_value, is_curr_value_empty);
        }
        switch (symbol) {
          case ' ':
            break;
          case '+':
            operations.push(Operator{'+', true});
            break;
          case '-':
            if (is_start_of_scope) {
              operations.push(Operator{'-', false});
              is_start_of_scope = false;
            } else {
              operations.push(Operator{'-', true});
            }
            break;
          case '(':
            is_start_of_scope = true;
            operations.push(Operator{'(', false});
            break;
          case ')':
            operations.pop();
            calcValue(operations, values);
            break;
        }
      }
    }
    if (!is_curr_value_empty) {
      pushValue(operations, values, curr_value, is_curr_value_empty);
    }
    if (!operations.empty()) {
      calcValue(operations, values);
    }
    return values.top();
  }

private:
  struct Operator {
    char oper_type;
    bool is_binary;
  };

  static const std::unordered_map<char,
                                  std::function<int(const int&, const int&)>>
      fn_map;

  static void calcValue(std::stack<Operator>& operations,
                        std::stack<int>& values) {
    if (operations.empty() || operations.top().oper_type == '(') {
      return;
    }
    if (operations.top() == Operator{'-', false}) {
      values.top() *= -1;
    } else {
      int right = values.top();
      values.pop();
      values.top() = fn_map.at(operations.top().oper_type)(values.top(), right);
    }
    operations.pop();
  }

  static void pushValue(std::stack<Operator>& operations,
                        std::stack<int>& values, int& curr_value,
                        bool& is_curr_value_empty) {
    if (operations.empty() || operations.top().oper_type == '(') {
      values.push(curr_value);
    } else {
      if (operations.top() == Operator{'-', false}) {
        curr_value *= -1;
        values.push(curr_value);
      } else {
        values.top() =
            fn_map.at(operations.top().oper_type)(values.top(), curr_value);
      }
      operations.pop();
    }
    is_curr_value_empty = true;
    curr_value = 0;
  }

  friend bool operator==(const Solution::Operator& left,
                         const Solution::Operator& right);
};

const std::unordered_map<char, std::function<int(const int&, const int&)>>
    Solution::fn_map = {{'+',
                         [](const int& left, const int& right) {
                           return left + right;
                         }},
                        {'-', [](const int& left, const int& right) {
                           return left - right;
                         }}};

bool operator==(const Solution::Operator& left,
                const Solution::Operator& right) {
  return ((left.oper_type == right.oper_type) &&
          (left.is_binary == right.is_binary));
}

int main() {
  // std::string s = "1 + 1";
  // std::string s = " 2-1 + 2 ";
  std::string s = "(1+(4+5+2)-3)+(6+8)";
  std::cout << Solution::calculate(s) << '\n';
  return 0;
}
