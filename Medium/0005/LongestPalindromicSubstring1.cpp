// Given a string s, return the longest palindromic substring in s.
// O(n) time complexity, O(n) memory complexity solution
// Idea: Use Manacher's Algorithm

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    std::pair<int, int> max_odd_palindrome = getMaxOddPalindrome(s);
    std::pair<int, int> max_even_palindrome = getMaxEvenPalindrome(s);
    if (max_odd_palindrome.second > max_even_palindrome.second) {
      return s.substr(max_odd_palindrome.first, max_odd_palindrome.second);
    }
    return s.substr(max_even_palindrome.first, max_even_palindrome.second);
  }

private:
  static std::pair<int, int> getMaxOddPalindrome(std::string s) {
    std::vector<int> d1(s.size(), 0);
    std::pair<int, int> max_odd_palindrome{0, 1};
    int d1_size = static_cast<int>(d1.size());
    d1[0] = 1;
    int left = 0;
    int right = 0;
    for (int i = 1; i < d1_size; ++i) {
      int palindrom_counter = 1;
      if (i <= right) {
        palindrom_counter = std::min(right - i + 1, d1[right - i + left]);
      }
      while (((i + palindrom_counter) < d1_size) &&
             ((i - palindrom_counter) >= 0) &&
             (s[i + palindrom_counter] == s[i - palindrom_counter])) {
        ++palindrom_counter;
      }
      d1[i] = palindrom_counter;
      if (max_odd_palindrome.second < (2 * d1[i] - 1)) {
        max_odd_palindrome = {i - d1[i] + 1, 2 * d1[i] - 1};
      }
      if ((i + palindrom_counter - 1) > right) {
        right = i + palindrom_counter - 1;
        left = i - palindrom_counter + 1;
      }
    }
    return max_odd_palindrome;
  }

  static std::pair<int, int> getMaxEvenPalindrome(std::string s) {
    std::vector<int> d2(s.size(), 0);
    std::pair<int, int> max_even_palindrome{-1, -1};
    int d2_size = static_cast<int>(d2.size());
    int left = 0;
    int right = -1;
    for (int i = 1; i < d2_size; ++i) {
      int palindrom_counter = 0;
      if (i <= right) {
        palindrom_counter = std::min(right - i + 1, d2[right - i + left + 1]);
      }
      while ((i + palindrom_counter < d2_size) &&
             (i - palindrom_counter - 1 >= 0) &&
             (s[i + palindrom_counter] == s[i - palindrom_counter - 1])) {
        ++palindrom_counter;
      }
      d2[i] = palindrom_counter;
      if (max_even_palindrome.second < 2 * d2[i]) {
        max_even_palindrome = {i - d2[i], 2 * d2[i]};
      }
      if ((i + palindrom_counter - 1) > right) {
        right = i + palindrom_counter - 1;
        left = i - palindrom_counter;
      }
    }
    return max_even_palindrome;
  }
};