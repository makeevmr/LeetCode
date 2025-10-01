#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  [[nodiscard]] static int minDeletions(const std::string& s) {
    std::unordered_map<char, int> symbol_freq;
    for (const char& symbol : s) {
      ++symbol_freq[symbol];
    }
    int answer = 0;
    std::unordered_set<int> used_freq;
    for (auto [_, freq] : symbol_freq) {
      while (freq > 0 && used_freq.find(freq) != used_freq.end()) {
        --freq;
        ++answer;
      }
      used_freq.insert(freq);
    }
    return answer;
  }
};
