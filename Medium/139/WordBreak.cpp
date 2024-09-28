/* Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a
space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Time complexity: O(n ^ 3)
Additional memory complexity: O(n)
Idea: use dynamic programming (answer can we construct s[0..i] substr on step i)
*/

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    [[nodiscard]] static bool wordBreak(const std::string& s, std::vector<std::string>& word_dict) {
        std::unordered_set<std::string> words_map;
        for (auto& str : word_dict) {
            words_map.insert(std::move(str));
        }
        std::vector<int> constructed_prefs;
        int s_size = static_cast<int>(s.size());
        for (int i = 0; i < s_size; ++i) {
            if (words_map.contains(s.substr(0, i + 1))) {
                constructed_prefs.push_back(i);
            } else {
                for (const auto& ind : constructed_prefs) {
                    if (words_map.contains(s.substr(ind + 1, i - ind))) {
                        constructed_prefs.push_back(i);
                        break;
                    }
                }
            }
        }
        return !constructed_prefs.empty() && constructed_prefs.back() == s_size - 1;
    }
};