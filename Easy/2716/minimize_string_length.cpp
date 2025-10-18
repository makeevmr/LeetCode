#include <string>
#include <unordered_set>

class Solution {
public:
  [[nodiscard]] static int minimizedStringLength(const std::string s) {
    std::unordered_set<int> unique_symbols;
    for (const char& symbol : s) {
      unique_symbols.insert(symbol);
    }
    return static_cast<int>(unique_symbols.size());
  }
};
