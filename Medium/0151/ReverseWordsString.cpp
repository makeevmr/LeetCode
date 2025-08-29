#include <algorithm>
#include <iostream>
#include <string>

class Solution {
  static void pushWord(std::string& str_to_push, std::string& word) {
    if (!word.empty()) {
      std::reverse(word.begin(), word.end());
      if (str_to_push.empty()) {
        str_to_push += word;
      } else {
        str_to_push += " " + word;
      }
      word.clear();
    }
  }

public:
  static std::string reverseWords(const std::string& input_str) {
    std::string answer;
    std::size_t i = input_str.size();
    std::string word;
    do {
      --i;
      if (input_str[i] == ' ') {
        pushWord(answer, word);
      } else {
        word.push_back(input_str[i]);
        if (i == 0) {
          pushWord(answer, word);
        }
      }
    } while (i != 0);
    return answer;
  }
};

int main() {
  std::string input_str("a good   example");
  std::cout << Solution::reverseWords(input_str) << '\n';
  return 0;
}
