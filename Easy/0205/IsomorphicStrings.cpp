/* Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
Time complexity: O(|s| + |t|) = O(|s|)
Additional memory complexity: O(power of the alphabet)
Idea: use unordered_map to store mapping between symbols
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isIsomorphic(const std::string &s, const std::string &t) {
        std::unordered_map<char, char> st_mapping;
        std::unordered_map<char, char> ts_mapping;
        for (std::size_t i = 0; i < s.size(); ++i) {
            auto st_iter = st_mapping.find(s[i]);
            if (st_iter != st_mapping.end()) {
                if (st_iter->second != t[i] || !ts_mapping.contains(t[i]) ||
                    ts_mapping[t[i]] != s[i]) {
                    return false;
                }
            } else {
                if (ts_mapping.contains(t[i])) {
                    return false;
                }
                st_mapping[s[i]] = t[i];
                ts_mapping[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    // std::string s = "egg";
    // std::string t = "add";
    // std::string s = "foo";
    // std::string t = "bar";
    std::string s = "paper";
    std::string t = "title";
    std::cout << Solution::isIsomorphic(s, t) << '\n';
    return 0;
}