#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> anagrams;
        std::unordered_map<std::string, std::pair<std::size_t, std::string>> anagrams_map;
        for (std::size_t i = 0; i < strs.size(); ++i) {
            std::string str_cpy = strs[i];
            std::sort(str_cpy.begin(), str_cpy.end());
            if (auto f_iter = anagrams_map.find(str_cpy); f_iter == anagrams_map.end()) {
                anagrams.push_back(std::vector<std::string>{std::move(strs[i])});
                anagrams_map.insert({str_cpy, {anagrams.size() - 1, str_cpy}});
            } else {
                if (f_iter->second.second == str_cpy) {
                    anagrams[f_iter->second.first].push_back(std::move(strs[i]));
                } else {
                    anagrams.push_back(std::vector<std::string>{strs[i]});
                    anagrams_map.insert({str_cpy, {anagrams.size() - 1, str_cpy}});
                }
            }
        }
        return anagrams;
    }
};

int main() {
    // std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::string> strs = {"a"};
    std::vector<std::vector<std::string>> anagrams = Solution::groupAnagrams(strs);
    for (const auto &item : anagrams) {
        for (const auto &str : item) {
            std::cout << str << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
