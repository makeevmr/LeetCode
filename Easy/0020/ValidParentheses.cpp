/* Given a string s containing just the characters '(', ')', '{', '}', '[' and
']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Time complexity: O(n), where n is length of str
Additional memory complexity: O(n)
Idea: use stack to store all open brackets
*/

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  static bool isValid(const std::string& s) {
    std::stack<char> opened_brackets;
    for (const auto& bracket : s) {
      if (bracket == '(' || bracket == '[' || bracket == '{') {
        opened_brackets.push(bracket);
      } else {
        switch (bracket) {
          case ')':
            if (opened_brackets.empty() || opened_brackets.top() != '(') {
              return false;
            }
            opened_brackets.pop();
            break;
          case ']':
            if (opened_brackets.empty() || opened_brackets.top() != '[') {
              return false;
            }
            opened_brackets.pop();
            break;
          case '}':
            if (opened_brackets.empty() || opened_brackets.top() != '{') {
              return false;
            }
            opened_brackets.pop();
            break;
        }
      }
    }
    return opened_brackets.empty();
  }
};

int main() {
  // std::string s = "()";
  // std::string s = "()[]{}";
  std::string s = "(}";
  std::cout << Solution::isValid(s) << '\n';
  return 0;
}
