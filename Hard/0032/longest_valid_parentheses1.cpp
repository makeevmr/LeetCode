#include <stack>
#include <string>

class Solution {
public:
    [[nodiscard]] static int longestValidParentheses(const std::string& s) {
        std::stack<int> stack;
        stack.push(-1);
        int answer = 0;
        const int s_size = static_cast<int>(s.size());
        for (int i = 0; i < s_size; ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    answer = std::max(answer, i - stack.top());
                }
            }
        }
        return answer;
    }
};