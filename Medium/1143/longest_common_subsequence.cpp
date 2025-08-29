#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
  [[nodiscard]] static int longestCommonSubsequence(std::string& text1,
                                                    std::string& text2) {
    size_t text1_size = text1.size();
    size_t text2_size = text2.size();
    if (text1_size > text2_size) {
      std::swap(text1, text2);
      std::swap(text1_size, text2_size);
    }
    std::unordered_map<char, std::vector<int>> symbol_indexes_map;
    for (size_t i = 0; i < text2_size; ++i) {
      symbol_indexes_map[text2[i]].push_back(static_cast<int>(i));
    }
    int max_dp_size = text1_size + 1;
    std::vector<int> dp(max_dp_size, std::numeric_limits<int>::max());
    dp[0] = -1;
    int dp_size = 1;
    for (const char& new_s : text1) {
      const auto& f_iter = symbol_indexes_map.find(new_s);
      if (f_iter == symbol_indexes_map.end()) {
        continue;
      }
      const std::vector<int>& indexes = f_iter->second;
      const int indexes_size = static_cast<int>(indexes.size());
      int j = indexes_size - 1;
      for (int i = dp_size - 1; i >= 0; --i) {
        while ((j - 1) >= 0 && indexes[j - 1] > dp[i]) {
          --j;
        }
        if (indexes[j] <= dp[i]) {
          continue;
        }
        if (dp[i + 1] > indexes[j]) {
          dp[i + 1] = indexes[j];
        }
      }
      if (dp[dp_size] != std::numeric_limits<int>::max()) {
        ++dp_size;
      }
    }
    return dp_size - 1;
  }
};

int main() {
  std::string text1 = "yzebsbuxmtcfmtodclszgh";
  std::string text2 = "ejevmhcvshclydqrulwbyha";
  std::cout << Solution::longestCommonSubsequence(text1, text2) << '\n';
  return 0;
}