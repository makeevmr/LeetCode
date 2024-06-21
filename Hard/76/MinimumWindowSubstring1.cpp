/* Given two strings s and t of lengths m and n respectively, return the minimum window substring
of s such that every character in t (including duplicates) is included in the window. If there
is no such substring, return the empty string "". */
// Time complexity: O(n)
// Additional memory complexity: O(1)
// Idea: use two pointers (left, right), move right pointer until meet a valid substr, then move
// left pointer until substr becomes invalid once again

#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Solution {
public:
    static std::string minWindow(const std::string &s, const std::string t) {
        std::vector<int> symbols_counter(128, 0);
        for (const auto &symbol : t) {
            ++symbols_counter[symbol];
        }
        int diff_counter = static_cast<int>(t.size());
        int left_ind = 0;
        int right_ind = -1;
        int s_size = static_cast<int>(s.size());
        std::pair<int, int> min_window = {-1, std::numeric_limits<int>::max()};
        while (right_ind < s_size) {
            ++right_ind;
            if (symbols_counter[s[right_ind]] > 0) {
                --diff_counter;
            }
            --symbols_counter[s[right_ind]];
            while (diff_counter == 0) {
                if (min_window.second > right_ind - left_ind + 1) {
                    min_window = {left_ind, right_ind - left_ind + 1};
                }
                ++symbols_counter[s[left_ind]];
                if (symbols_counter[s[left_ind]] > 0) {
                    ++diff_counter;
                }
                ++left_ind;
            }
        }
        return min_window.first == -1 ? "" : s.substr(min_window.first, min_window.second);
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
