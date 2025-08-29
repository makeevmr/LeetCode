#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> findSubstring(const std::string& s,
                                        const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> words_count_map;
    std::unordered_map<std::string, int>::iterator e_words_count_iter =
        words_count_map.end();
    for (const std::string& word : words) {
      ++words_count_map[word];
    }
    size_t words_array_size = words.size();
    size_t word_size = words[0].size();
    size_t s_size = s.size();
    std::vector<int> answer;
    if (s_size < word_size) {
      return answer;
    }
    for (size_t i = 0; i < word_size; ++i) {
      size_t words_count = 0;
      size_t left_index = i;
      std::unordered_map<std::string, int> words_seen_map;
      std::unordered_map<std::string, int>::iterator e_iter =
          words_seen_map.end();
      for (size_t j = i; j <= s_size - word_size; j += word_size) {
        const std::string& substr = s.substr(j, word_size);
        if (words_count_map.find(substr) != e_iter) {
          ++words_seen_map[substr];
          while (words_seen_map[substr] > words_count_map[substr]) {
            const std::string& new_substr = s.substr(left_index, word_size);
            --words_seen_map[new_substr];
            --words_count;
            left_index += word_size;
          }
          ++words_count;
          if (words_count == words_array_size) {
            answer.push_back(left_index);
            --words_seen_map[s.substr(left_index, word_size)];
            left_index += word_size;
            --words_count;
          }
        } else {
          words_seen_map.clear();
          left_index = j + word_size;
          words_count = 0;
        }
      }
    }
    return answer;
  }
};

int main() {
  /* std::string s = "barfoothefoobarman"; */
  /* std::vector<std::string> words = {"foo", "bar"}; */
  /* std::string s = "wordgoodgoodgoodbestword"; */
  /* std::vector<std::string> words = {"word", "good", "best", "word"}; */
  std::string s = "barfoofoobarthefoobarman";
  std::vector<std::string> words = {"bar", "foo", "the"};
  std::vector<int> answer = Solution::findSubstring(s, words);
  for (int number : answer) {
    std::cout << number << ' ';
  }
  std::cout << '\n';
  return 0;
}
