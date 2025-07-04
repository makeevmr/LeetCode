/* Given an array of strings strs, group the anagrams together. You can return the answer in any
order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
Time complexity: O(n * k), where n is size of strs, k is size of word
Additional memory complexity: O(n * k)
Idea: iterate through vector, sort each word using counting sort, push new word to the unordered_map
with sorted word as a key
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        int32_t word_ind = 0;
        std::unordered_map<std::string, std::vector<int32_t>> anagrams_map;
        for (const std::string &word : strs) {
            anagrams_map[getSortedCopy(word)].push_back(word_ind);
            ++word_ind;
        }
        std::vector<std::vector<std::string>> anagrams(anagrams_map.size());
        u_int32_t anagrams_ind = 0;
        for (auto b_iter = anagrams_map.begin(); b_iter != anagrams_map.end(); ++b_iter) {
            for (std::size_t i = 0; i < b_iter->second.size(); ++i) {
                anagrams[anagrams_ind].push_back(std::move(strs[b_iter->second[i]]));
            }
            ++anagrams_ind;
        }
        return anagrams;
    }

private:
    static std::string getSortedCopy(const std::string &str) {
        const u_int32_t str_size = 26;
        std::string sorted_str;
        sorted_str.reserve(str_size);
        int symbol_count[str_size] = {0};
        for (const auto &symbol : str) {
            ++symbol_count[symbol - 97];
        }
        for (u_int32_t i = 0; i < str_size; ++i) {
            sorted_str += std::string(symbol_count[i], i + 97);
        }
        return sorted_str;
    }
};

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // std::vector<std::string> strs = {"a"};
    std::vector<std::vector<std::string>> anagrams = Solution::groupAnagrams(strs);
    for (const auto &item : anagrams) {
        for (const auto &str : item) {
            std::cout << str << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}