/* Given two strings s and t, return true if t is an anagram of s, and false
otherwise. An Anagram is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly once.
Time complexity: O(n)
Additional memory complexity: O(power of alphabet)
Idea: use hashmap to store frequency of each symbol
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  static bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, int> s_freq;
    std::unordered_map<char, int> t_freq;
    for (std::size_t i = 0; i < s.size(); ++i) {
      ++s_freq[s[i]];
      ++t_freq[t[i]];
    }
    return s_freq == t_freq;
  }
};

int main() {
  // std::string s = "anagram";
  // std::string t = "nagaram";
  std::string s = "rat";
  std::string t = "car";
  std::cout << Solution::isAnagram(s, t) << '\n';
  return 0;
}
