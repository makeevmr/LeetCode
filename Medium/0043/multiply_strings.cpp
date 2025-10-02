#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::string multiply(std::string& num1,
                                            std::string& num2) {
    if (num1.size() < num2.size()) {
      std::swap(num1, num2);
    }
    const std::size_t num1_size = num1.size();
    const std::size_t num2_size = num2.size();
    const std::size_t total_size = num1_size + num2_size;
    std::vector<std::vector<int>> mult_matrix(num2_size,
                                              std::vector(total_size, 0));
    std::size_t offset = 0;
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int carry = 0;
    for (std::size_t i = 0; i < num2.size(); ++i) {
      carry = 0;
      std::size_t j = 0;
      for (const char& num1_symb : num1) {
        const int new_num = (num1_symb - '0') * (num2[i] - '0') + carry;
        carry = new_num / 10;
        mult_matrix[i][j + offset] = new_num % 10;
        ++j;
      }
      mult_matrix[i][j + offset] = carry;
      ++offset;
    }
    std::stack<int> stack_sum;
    carry = 0;
    for (std::size_t j = 0; j < total_size; ++j) {
      int curr_sum = 0;
      for (std::size_t i = 0; i < num2_size; ++i) {
        curr_sum += mult_matrix[i][j];
      }
      curr_sum += carry;
      carry = curr_sum / 10;
      stack_sum.push(curr_sum % 10);
    }
    stack_sum.push(carry);
    while (!stack_sum.empty() && stack_sum.top() == 0) {
      stack_sum.pop();
    }
    std::string answer;
    while (!stack_sum.empty()) {
      answer.push_back('0' + stack_sum.top());
      stack_sum.pop();
    }
    if (answer.empty()) {
      answer.push_back('0');
    }
    return answer;
  }
};
