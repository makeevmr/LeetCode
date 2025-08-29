// Given a string s, return the longest palindromic substring in s.
// O(n^2) time complexity, O(n^2) memory complexity solution
// Idea: Dynamic programing with 2 dimensions (start, end) positions of
// substring

#include <string>
#include <vector>

class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    std::string answer;
    int s_size = static_cast<int>(s.size());
    std::vector<std::vector<bool>> is_palindrome(
        s.size(), std::vector<bool>(s.size(), false));
    for (int end = 0; end < s_size; ++end) {
      for (int start = end; start >= 0; --start) {
        if (end - start <= 1) {
          is_palindrome[start][end] = s[start] == s[end];
        } else {
          is_palindrome[start][end] =
              (s[start] == s[end]) && (is_palindrome[start + 1][end - 1]);
        }
        if (is_palindrome[start][end] &&
            ((end - start + 1) > static_cast<int>(answer.size()))) {
          answer = s.substr(start, end - start + 1);
        }
      }
    }
    return answer;
  }
};
