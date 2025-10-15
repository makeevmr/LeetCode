#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <execution>

class Solution {
public:
  [[nodiscard]] static std::vector<std::string> wordSubsets(
      const std::vector<std::string>& words1,
      const std::vector<std::string>& words2) {
    std::unordered_map<char, int> max_words2_freq;
    for (const auto& word : words2) {
      const auto& new_freq = getSymbolsFreq(word);
      std::for_each(std::execution::unseq, new_freq.begin(), new_freq.end(),
                    [&max_words2_freq](const std::pair<char, int>& new_freq) {
                      const auto& [symbol, freq] = new_freq;
                      if (max_words2_freq[symbol] < freq) {
                        max_words2_freq[symbol] = freq;
                      }
                    });
    }
    std::vector<std::string> answer;
    std::for_each(
        std::execution::unseq, words1.begin(), words1.end(),
        [&answer, &max_words2_freq](const std::string& new_word) {
          auto word_freq = getSymbolsFreq(new_word);
          for (const auto& [max2_symbol, max2_freq] : max_words2_freq) {
            if (max2_freq > word_freq[max2_symbol]) {
              return;
            }
          }
          answer.push_back(new_word);
        });
    return answer;
  }

private:
  static std::unordered_map<char, int> getSymbolsFreq(const std::string& str) {
    std::unordered_map<char, int> symbols_freq;
    std::for_each(std::execution::unseq, str.begin(), str.end(),
                  [&symbols_freq](const char& symbol) {
                    ++symbols_freq[symbol];
                  });
    return symbols_freq;
  }
};