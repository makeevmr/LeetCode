#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static std::vector<int> findAnagrams(const std::string& s,
                                                     const std::string& p) {
    const int s_size = static_cast<int>(s.size());
    const int p_size = static_cast<int>(p.size());
    if (s_size < p_size) {
      return {};
    }
    std::unordered_map<char, int> p_freq;
    for (const char& symbol : p) {
      ++p_freq[symbol];
    }
    int diff = static_cast<int>(p_freq.size());
    std::vector<int> ans;
    int s_ind = 0;
    while (s_ind < p_size) {
      if (auto f_iter = p_freq.find(s[s_ind]); f_iter != p_freq.end()) {
        --f_iter->second;
        if (f_iter->second == 0) {
          --diff;
        }
        if (f_iter->second == -1) {
          ++diff;
        }
      }
      ++s_ind;
    }
    if (diff == 0) {
      ans.push_back(0);
    }
    int left = 0;
    int right = p_size;
    while (right < s_size) {
      if (auto f_iter = p_freq.find(s[right]); f_iter != p_freq.end()) {
        --f_iter->second;
        if (f_iter->second == 0) {
          --diff;
        }
        if (f_iter->second == -1) {
          ++diff;
        }
      }
      if (auto f_iter = p_freq.find(s[left]); f_iter != p_freq.end()) {
        ++f_iter->second;
        if (f_iter->second == 0) {
          --diff;
        }
        if (f_iter->second == 1) {
          ++diff;
        }
      }
      if (diff == 0) {
        ans.push_back(left + 1);
      }
      ++left;
      ++right;
    }
    return ans;
  }
};