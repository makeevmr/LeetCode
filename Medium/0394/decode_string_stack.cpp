#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
  [[nodiscard]] static std::string decodeString(const std::string& s) {
    std::stack<std::pair<std::string, int>> decode_stack;
    size_t ind = 0;
    size_t s_size = s.size();
    std::string curr_str;
    std::string curr_num;
    while (ind < s_size) {
      while ((ind < s_size) && std::isalpha(s[ind]) != 0) {
        curr_str.push_back(s[ind]);
        ++ind;
      }
      while ((ind < s_size) && std::isdigit(s[ind]) != 0) {
        curr_num.push_back(s[ind]);
        ++ind;
      }
      if (ind == s_size) {
        break;
      }
      if (s[ind] == '[') {
        decode_stack.emplace(std::move(curr_str), std::stoi(curr_num));
        curr_str.clear();
        curr_num.clear();
      } else {
        const auto [str_frag, reps] = std::move(decode_stack.top());
        decode_stack.pop();
        std::string tmp;
        tmp.reserve(curr_str.size() * reps);
        for (int i = 0; i < reps; ++i) {
          tmp.append(curr_str);
        }
        curr_str = str_frag + tmp;
        curr_num.clear();
      }
      ++ind;
    }
    return curr_str;
  }
};
