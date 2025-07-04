/* A transformation sequence from word beginWord to word endWord using a dictionary wordList is a
sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the
shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Time complexity: O(wordList_size ^ 2 * beginWord_size)
Additional memory complexity: O(wordList_size * beginWord_size)
Idea: use BFS to find shortest path in unweighted graph between beginWord and endWord
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Solution {
public:
    static int ladderLength(const std::string &beginWord, const std::string &endWord,
                            const std::vector<std::string> &wordList) {
        std::queue<std::string> queue;
        std::vector<bool> visited_nodes(wordList.size() + 1, false);
        queue.push(beginWord);
        visited_nodes[wordList.size()] = true;
        int words_in_path = 1;
        while (!queue.empty()) {
            std::size_t queue_size = queue.size();
            for (std::size_t i = 0; i < queue_size; ++i) {
                std::string curr_word = std::move(queue.front());
                queue.pop();
                if (curr_word == endWord) {
                    return words_in_path;
                }
                for (std::size_t i = 0; i < wordList.size(); ++i) {
                    if (!visited_nodes[i] && isAdjacentPair(curr_word, wordList[i])) {
                        queue.push(wordList[i]);
                        visited_nodes[i] = true;
                    }
                }
            }
            ++words_in_path;
        }
        return 0;
    }

private:
    static bool isAdjacentPair(const std::string &word_l, const std::string &word_r) {
        int diff = 0;
        for (std::size_t i = 0; i < word_l.size(); ++i) {
            if (word_l[i] != word_r[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};

int main() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // std::string beginWord = "hit";
    // std::string endWord = "cog";
    // std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
    std::cout << Solution::ladderLength(beginWord, endWord, wordList) << '\n';
    return 0;
}
