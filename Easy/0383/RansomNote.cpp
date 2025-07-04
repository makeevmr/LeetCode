// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using
// the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.
// Time complexity: O(n + m), where n is size of ransomNote, m is sizeof magazine
// Additional memory complexity: O(power of alphabet)
// Idea: use unordered_map

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    static bool canConstruct(const std::string &ransomNote, const std::string &magazine) {
        std::unordered_map<char, int> ransom_freq;
        for (const auto &symbol : ransomNote) {
            ++ransom_freq[symbol];
        }
        int unique_counter = static_cast<int>(ransom_freq.size());
        for (const auto &symbol : magazine) {
            if (ransom_freq.contains(symbol)) {
                --ransom_freq[symbol];
                if (ransom_freq[symbol] == 0) {
                    --unique_counter;
                }
            }
        }
        return unique_counter == 0;
    }
};

int main() {
    std::string ransomNote = "aa";
    std::string magazine = "aab";
    std::cout << Solution::canConstruct(ransomNote, magazine) << '\n';
    return 0;
}
