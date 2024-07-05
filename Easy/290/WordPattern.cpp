/* Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a
non-empty word in s.
Time complexity: O(n), where n is length of string s
Additional memory complexity: O(power of alphabet * word length)
Idea: store letter word relation in vector and used words in unordered_set
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    static bool wordPattern(const std::string &pattern, const std::string &s) {
        std::string curr_word;
        std::vector<std::string> word_map(26);
        std::unordered_set<std::string> used_words;
        std::size_t s_index = 0;
        std::size_t s_size = s.size();
        std::size_t pattern_size = pattern.size();
        for (std::size_t i = 0; i < pattern_size; ++i) {
            while (s_index < s_size && s[s_index] != ' ') {
                curr_word.push_back(s[s_index]);
                ++s_index;
            }
            if (curr_word.empty()) {
                return false;
            }
            int map_index = pattern[i] - 'a';
            if (word_map[map_index].empty()) {
                if (used_words.contains(curr_word)) {
                    return false;
                }
                word_map[map_index] = curr_word;
                used_words.insert(std::move(curr_word));
            } else if (word_map[map_index] != curr_word) {
                return false;
            }
            ++s_index;
            curr_word.clear();
        }
        return s_index >= s_size ? true : false;
    }
};

int main() {
    // std::string pattern = "abba";
    // std::string s = "dog cat cat dog";
    // std::string pattern = "abba";
    // std::string s = "dog cat cat fish";
    std::string pattern = "aaaa";
    std::string s = "dog cat cat dog";
    std::cout << Solution::wordPattern(pattern, s) << '\n';
    return 0;
}