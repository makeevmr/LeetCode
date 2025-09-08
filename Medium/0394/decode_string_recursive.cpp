#include <cctype>
#include <string>
#include <cctype>

class Solution {
public:
  [[nodiscard]] static std::string decodeString(const std::string& s) {
    return helper(s, s.size(), 0).first;
  }

private:
  [[nodiscard]] static std::pair<std::string, size_t> helper(
      const std::string& s, const std::size_t& s_size, size_t ind) {
    std::string decoded_str;
    std::string num;
    while (ind < s_size && s[ind] != ']') {
      while (ind < s_size && std::isalpha(s[ind]) != 0) {
        decoded_str.push_back(s[ind]);
        ++ind;
      }
      while (ind < s_size && std::isdigit(s[ind]) != 0) {
        num.push_back(s[ind]);
        ++ind;
      }
      if (!num.empty()) {
        const auto& [new_str, new_ind] = helper(s, s_size, ind + 1);
        ind = new_ind;
        for (int i = 0; i < std::stoi(num); ++i) {
          decoded_str.append(new_str);
        }
        num.clear();
      }
    }
    return std::pair<std::string, size_t>{decoded_str, ind + 1};
  }
};