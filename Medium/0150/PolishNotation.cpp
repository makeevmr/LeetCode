/* You are given an array of strings tokens that represents an arithmetic expression in a Reverse
Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Time complexity: O(n * k), where n is tokens.size(), k is average token size
Additional memory complexity: O(n * k)
Idea: use stack to compute expressions in reverse polish notation
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    static int evalRPN(const std::vector<std::string> &tokens) {
        std::stack<int> expressions_stack;
        for (const auto &token : tokens) {
            if ('0' <= token.back() && token.back() <= '9') {
                expressions_stack.push(std::stoi(token));
            } else {
                int right_operand = expressions_stack.top();
                expressions_stack.pop();
                int left_operand = expressions_stack.top();
                expressions_stack.pop();
                if (token == "+") {
                    expressions_stack.push(left_operand + right_operand);
                } else if (token == "-") {
                    expressions_stack.push(left_operand - right_operand);
                } else if (token == "*") {
                    expressions_stack.push(left_operand * right_operand);
                } else {
                    expressions_stack.push(left_operand / right_operand);
                }
            }
        }
        return expressions_stack.top();
    }
};

int main() {
    // std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    // std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
    std::vector<std::string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                                       "/",  "*", "17", "+", "5", "+"};
    std::cout << Solution::evalRPN(tokens) << '\n';
    return 0;
}
