#include <string>

class Solution {
public:
  [[nodiscard]] static bool backspaceCompare(const std::string& s,
                                             const std::string& t) {
    const int s_size = static_cast<int>(s.size());
    const int t_size = static_cast<int>(t.size());
    int s_ind = s_size - 1;
    int t_ind = t_size - 1;
    int s_to_pass = 0;
    int t_to_pass = 0;
    while (s_ind >= 0 && t_ind >= 0) {
      while (s_ind >= 0 && (s[s_ind] == '#' || s_to_pass > 0)) {
        if (s[s_ind] == '#') {
          ++s_to_pass;
        } else {
          --s_to_pass;
        }
        --s_ind;
      }
      while (t_ind >= 0 && (t[t_ind] == '#' || t_to_pass > 0)) {
        if (t[t_ind] == '#') {
          ++t_to_pass;
        } else {
          --t_to_pass;
        }
        --t_ind;
      }
      if (s_ind >= 0 && t_ind >= 0) {
        if (s[s_ind] != t[t_ind]) {
          return false;
        }
        --s_ind;
        --t_ind;
      }
    }
    while (s_ind >= 0) {
      while (s_ind >= 0 && (s[s_ind] == '#' || s_to_pass > 0)) {
        if (s[s_ind] == '#') {
          ++s_to_pass;
        } else {
          --s_to_pass;
        }
        --s_ind;
      }
      if (s_ind >= 0) {
        return false;
      }
    }
    while (t_ind >= 0) {
      while (t_ind >= 0 && (t[t_ind] == '#' || t_to_pass > 0)) {
        if (t[t_ind] == '#') {
          ++t_to_pass;
        } else {
          --t_to_pass;
        }
        --t_ind;
      }
      if (t_ind >= 0) {
        return false;
      }
    }
    return true;
  }
};