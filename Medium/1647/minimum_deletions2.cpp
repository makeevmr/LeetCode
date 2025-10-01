#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int minDeletions(const std::string& s) {
    std::unordered_map<char, int> symbol_freq;
    for (const char& symbol : s) {
      ++symbol_freq[symbol];
    }
    int max_freq = 0;
    std::unordered_map<int, int> symbols_same_freq;
    for (const auto& [_, freq] : symbol_freq) {
      ++symbols_same_freq[freq];
      max_freq = std::max(max_freq, freq);
    }
    int answer = 0;
    int curr_freq = max_freq;
    int curr_symbols_same_freq = symbols_same_freq[curr_freq];
    while (curr_freq > 0) {
      if (curr_symbols_same_freq > 0) {
        answer += curr_symbols_same_freq - 1;
        --curr_symbols_same_freq;
      }
      --curr_freq;
      curr_symbols_same_freq += symbols_same_freq[curr_freq];
    }
    return answer;
  }
};