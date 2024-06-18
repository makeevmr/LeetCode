// Given two strings needle and haystack, return the index of the first occurrence of needle in
// haystack, or -1 if needle is not part of haystack
// Time complexity: O(n + k), where n is size of haystack, k is size of needle
// Additional memory complexity: O(n + k)
// Idea: use KMP algorithm

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static int strStr(const std::string &haystack, const std::string &needle) {
        int haystack_size = static_cast<int>(haystack.size());
        int needle_size = static_cast<int>(needle.size());
        std::vector<int> needle_pf = prefixFunction(needle);
        int i = 0;
        int j = 0;
        while (i < haystack_size) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                if (j > 0) {
                    j = needle_pf[j - 1];
                } else {
                    ++i;
                }
            }
            if (j == needle_size) {
                return i - j;
            }
        }
        return -1;
    }

private:
    static std::vector<int> prefixFunction(const std::string &str) {
        int str_size = static_cast<int>(str.size());
        std::vector<int> pf(str_size);
        for (int i = 1; i < str_size; ++i) {
            int j = pf[i - 1];
            while (j > 0 && str[i] != str[j]) {
                j = pf[j - 1];
            }
            if (str[i] == str[j]) {
                ++j;
            }
            pf[i] = j;
        }
        return pf;
    }
};

int main() {
    // std::string haystack = "sadbutsad";
    // std::string needle = "sad";
    // std::string haystack = "leetcode";
    // std::string needle = "leeto";
    std::string haystack = "aaa";
    std::string needle = "aaa";
    std::cout << Solution::strStr(haystack, needle) << '\n';
    return 0;
}
