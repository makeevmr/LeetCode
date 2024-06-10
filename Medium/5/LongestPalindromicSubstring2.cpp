// Given a string s, return the longest palindromic substring in s.
// O(n^2) time complexity, O(1) memory complexity solution
// Idea: Expand around center

#include <string>

class Solution {
public:
    static std::string longestPalindrome(std::string s) {
        std::string answer;
        int s_size = static_cast<int>(s.size());
        int left_ind = 0;
        int right_ind = 0;
        for (int i = 0; i < (2 * s_size - 1); ++i) {
            if (i % 2 == 0) {
                left_ind = i / 2;
                right_ind = i / 2;
            } else {
                left_ind = (i - 1) / 2;
                right_ind = (i + 1) / 2;
            }
            while ((left_ind > 0) && (right_ind < s_size - 1) && (s[left_ind] == s[right_ind])) {
                --left_ind;
                ++right_ind;
            }
            if (s[left_ind] != s[right_ind]) {
                ++left_ind;
                --right_ind;
            }
            int new_substr_len = right_ind - left_ind + 1;
            if (new_substr_len > static_cast<int>(answer.size())) {
                answer = s.substr(left_ind, new_substr_len);
            }
        }
        return answer;
    }
};
