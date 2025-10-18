#include <string>

class Solution {
public:
  [[nodiscard]] static bool makeStringsEqual(const std::string& s,
                                             const std::string& target) {
    const std::size_t s_size = s.size();
    int count_1 = 0;
    int count_01 = 0;
    int count_10 = 0;
    for (std::size_t i = 0; i < s_size; ++i) {
      if (s[i] == '1') {
        ++count_1;
        if (target[i] == '0') {
          ++count_10;
        }
      }
      if (s[i] == '0' && target[i] == '1') {
        ++count_01;
      }
    }
    if (count_01 + count_10 == 0) {
      return true;
    }
    return (count_10 != count_1 || count_01 != 0) &&
           (count_01 == 0 || count_1 != 0);
  }
};