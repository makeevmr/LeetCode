/* Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
Time complexity: O(s1_size + s2_size)
Additional memory complexity: O(s1_size)
Idea: use unordered_map to store frequencies of s1 string and frequencies of s2
substring, count difference in hasmaps if difference == 0 than return true;
*/

#include <string>
#include <unordered_map>

class Solution {
public:
  bool checkInclusion(const std::string& s1, const std::string& s2) {
    std::size_t s1_size = s1.size();
    std::size_t s2_size = s2.size();
    if (s1_size > s2_size) {
      return false;
    }
    std::unordered_map<char, int> s1_freq;
    for (const auto& symbol : s1) {
      ++s1_freq[symbol];
    }
    std::unordered_map<char, int> s2_sub_freq;
    for (std::size_t i = 0; i < s1_size; ++i) {
      if (s1_freq.contains(s2[i])) {
        ++s2_sub_freq[s2[i]];
      }
    }
    int difference = 0;
    for (auto b_iter = s1_freq.begin(), e_iter = s1_freq.end();
         b_iter != e_iter; ++b_iter) {
      if (!s2_sub_freq.contains(b_iter->first) ||
          s2_sub_freq[b_iter->first] != b_iter->second) {
        ++difference;
      }
    }
    if (difference == 0) {
      return true;
    }
    for (std::size_t i = s1_size; i < s2_size; ++i) {
      std::size_t erased = i - s1_size;
      if (s1_freq.contains(s2[erased])) {
        --s2_sub_freq[s2[erased]];
        if (s1_freq[s2[erased]] == s2_sub_freq[s2[erased]]) {
          --difference;
        }
        if (s1_freq[s2[erased]] == s2_sub_freq[s2[erased]] + 1) {
          ++difference;
        }
      }
      if (s1_freq.contains(s2[i])) {
        ++s2_sub_freq[s2[i]];
        if (s1_freq[s2[i]] == s2_sub_freq[s2[i]]) {
          --difference;
        }
        if (s1_freq[s2[i]] + 1 == s2_sub_freq[s2[i]]) {
          ++difference;
        }
      }
      if (difference == 0) {
        return true;
      }
    }
    return false;
  };
};

int main() {
  return 0;
}
