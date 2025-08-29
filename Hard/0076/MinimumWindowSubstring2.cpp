/* Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"". */
// Time complexity: O(n * lon(n))
// Additional memory complexity: O(k), where k is power of the alphabet
// Idea: use Binary search for window size, for fixed window size use O(n) time
// to compute the answer (yes/no such window found)

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::string minWindow(const std::string& s, const std::string& t) {
    if (s.size() < t.size() || s.size() == 0 || t.size() == 0) {
      return "";
    }
    std::size_t left_size = 1;
    std::size_t right_size = s.size();
    while (left_size < right_size) {
      std::size_t middle = (left_size + right_size) / 2;
      std::pair<int, int> curr_substr = getSubstr(s, t, middle);
      if (curr_substr != std::pair<int, int>(-1, -1)) {
        right_size = middle;
      } else {
        left_size = middle + 1;
      }
    }
    std::pair<int, int> min_substr = getSubstr(s, t, left_size);
    if (min_substr == std::pair<int, int>(-1, -1)) {
      return "";
    }
    return s.substr(min_substr.first, min_substr.second - min_substr.first + 1);
  }

private:
  static std::pair<int, int> getSubstr(const std::string& s,
                                       const std::string& t,
                                       std::size_t substr_size) {
    std::unordered_map<char, int> hashmap_t;
    for (const auto& symbol : t) {
      ++hashmap_t[symbol];
    }
    std::unordered_map<char, int> hashmap_substr;
    for (std::size_t i = 0; i < substr_size; ++i) {
      if (hashmap_t.contains(s[i])) {
        ++hashmap_substr[s[i]];
      }
    }
    int count_diff = 0;
    for (auto b_iter = hashmap_t.begin(); b_iter != hashmap_t.end(); ++b_iter) {
      auto f_iter = hashmap_substr.find(b_iter->first);
      if (f_iter == hashmap_substr.end() || f_iter->second < b_iter->second) {
        ++count_diff;
      }
    }
    if (count_diff == 0) {
      return {0, substr_size - 1};
    }
    for (std::size_t i = substr_size; i < s.size(); ++i) {
      char new_symbol = s[i];
      if (hashmap_t.contains(new_symbol)) {
        ++hashmap_substr[new_symbol];
        if (hashmap_substr[new_symbol] == hashmap_t[new_symbol]) {
          --count_diff;
        }
      }
      char deleted_symbol = s[i - substr_size];
      if (hashmap_t.contains(deleted_symbol)) {
        --hashmap_substr[deleted_symbol];
        if (hashmap_substr[deleted_symbol] + 1 == hashmap_t[deleted_symbol]) {
          ++count_diff;
        }
      }
      if (count_diff == 0) {
        return {i - substr_size + 1, i};
      }
    }
    return {-1, -1};
  }
};

int main() {
  // std::string s = "ADOBECODEBANC";
  // std::string t = "ABC";
  // // std::string s = "a";
  // // std::string t = "a";
  // // std::string s = "a";
  // // std::string t = "aa";
  std::string s = "cabefgecdaecf";
  std::string t = "cae";
  std::cout << Solution::minWindow(s, t) << '\n';
  return 0;
}
