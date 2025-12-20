#include <string>
#include <array>

class Solution {
public:
  [[nodiscard]] static int maxLengthBetweenEqualCharacters(
      const std::string& s) {
    int max_len = -1;
    const std::size_t alphabet_size = 26ULL;
    std::array<int, alphabet_size> first_occurance = {};
    for (std::size_t i = 0; i < alphabet_size; ++i) {
      first_occurance[i] = -1;
    }
    const int s_size = static_cast<int>(s.size());
    for (int i = 0; i < s_size; ++i) {
      const std::size_t index = s[i] - 'a';
      if (first_occurance[index] == -1) {
        first_occurance[index] = i;
      } else {
        max_len = std::max(max_len, i - first_occurance[index] - 1);
      }
    }
    return max_len;
  }
};