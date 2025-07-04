// Given two strings needle and haystack, return the index of the first occurrence of needle in
// haystack, or -1 if needle is not part of haystack
// Time complexity: O(n * (n - k + 1)), where n is size of haystack, k is size of needle
// Additional memory complexity: O(1)
// Idea: for every possible window, which are n - k + 1, compute in O(n) is needle and window are
// equivalent

#include <iostream>
#include <string>

class Solution {
public:
    static int strStr(const std::string &haystack, const std::string &needle) {
        int needle_size = static_cast<int>(needle.size());
        int haystack_size = static_cast<int>(haystack.size());
        for (int i = 0; i < haystack_size; ++i) {
            bool is_same_str = true;
            int haystack_index = i;
            for (int j = 0; j < needle_size; ++j) {
                if (needle[j] != haystack[haystack_index]) {
                    is_same_str = false;
                    break;
                }
            }
            ++haystack_index;
            if (is_same_str) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    // std::string haystack = "sadbutsad";
    // std::string needle = "sad";
    std::string haystack = "leetcode";
    std::string needle = "leeto";
    std::cout << Solution::strStr(haystack, needle) << '\n';
    return 0;
}
