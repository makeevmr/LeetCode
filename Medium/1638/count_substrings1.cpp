#include <string>

class Solution {
public:
  [[nodiscard]] static int countSubstrings(const std::string& s,
                                           const std::string& t) {
    int dpl[100][100] = {};
    int dpr[100][100] = {};
    const int s_size = static_cast<int>(s.size());
    const int t_size = static_cast<int>(t.size());
    for (int i = 0; i < s_size; ++i) {
      if (s[i] == t[0]) {
        dpl[i][0] = 1;
      }
    }
    for (int j = 0; j < t_size; ++j) {
      if (s[0] == t[j]) {
        dpl[0][j] = 1;
      }
    }
    for (int i = s_size - 1; i >= 0; --i) {
      if (s[i] == t[t_size - 1]) {
        dpr[i][t_size - 1] = 1;
      }
    }
    for (int j = t_size - 1; j >= 0; --j) {
      if (s[s_size - 1] == t[j]) {
        dpr[s_size - 1][j] = 1;
      }
    }
    for (int i = 1; i < s_size; ++i) {
      for (int j = 1; j < t_size; ++j) {
        if (s[i] == t[j]) {
          dpl[i][j] = dpl[i - 1][j - 1] + 1;
        }
      }
    }
    if (s_size >= 2 && t_size >= 2) {
      for (int i = static_cast<int>(s_size - 2); i >= 0; --i) {
        for (int j = static_cast<int>(t_size - 2); j >= 0; --j) {
          if (s[i] == t[j]) {
            dpr[i][j] = dpr[i + 1][j + 1] + 1;
          }
        }
      }
    }
    int answer = 0;
    for (int i = 0; i < s_size; ++i) {
      for (int j = 0; j < t_size; ++j) {
        if (s[i] != t[j]) {
          int left = 1;
          if (i > 0 && j > 0) {
            left += dpl[i - 1][j - 1];
          }
          int right = 1;
          if (i < s_size - 1 && j < t_size - 1) {
            right += dpr[i + 1][j + 1];
          }
          answer += left * right;
        }
      }
    }
    return answer;
  }
};