/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
Time complexity: O(n)
Additional memory complexity: O(power of alphabet)
Idea: use hashmap to store frequency of each symbol
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isAnagram(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> symbol_count;
        for (std::size_t i = 0; i < s.size(); ++i) {
            ++symbol_count[s[i]];
            --symbol_count[t[i]];
        }
        for (auto b_iter = symbol_count.begin(); b_iter != symbol_count.end(); ++b_iter) {
            if (b_iter->second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    // std::string s = "rat";
    // std::string t = "car";
    std::cout << Solution::isAnagram(s, t) << '\n';
    return 0;
}