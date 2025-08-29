/* A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: use two pointers (left, right), move left pointer until valid symbol is
met, move right pointer until valid symbol is met, than compare symbols
*/
#include <iostream>
#include <string>

class Solution {
public:
  static bool isPalindrome(const std::string& s) {
    int left_index = 0;
    int s_size = static_cast<int>(s.size());
    int right_index = s_size - 1;
    bool is_palindrome = true;
    while (left_index < right_index) {
      while ((left_index < s_size) &&
             (s[left_index] < 48 || s[left_index] > 57) &&
             (s[left_index] < 65 || s[left_index] > 90) &&
             (s[left_index] < 97 || s[left_index] > 122)) {
        ++left_index;
      }
      while ((right_index >= 0) &&
             (s[right_index] < 48 || s[right_index] > 57) &&
             (s[right_index] < 65 || s[right_index] > 90) &&
             (s[right_index] < 97 || s[right_index] > 122)) {
        --right_index;
      }
      if (left_index < right_index) {
        if ((s[left_index] == s[right_index]) ||
            (('A' <= s[left_index] && s[left_index] <= 'Z') &&
             ('a' <= s[right_index] && s[right_index] <= 'z') &&
             s[left_index] + 32 == s[right_index]) ||
            (('A' <= s[right_index] && s[right_index] <= 'Z') &&
             ('a' <= s[left_index] && s[left_index] <= 'z') &&
             s[right_index] + 32 == s[left_index])) {
          ++left_index;
          --right_index;
          continue;
        } else {
          is_palindrome = false;
          break;
        }
      }
    }
    return is_palindrome;
  }
};
