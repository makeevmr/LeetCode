class Solution {
public:
  [[nodiscard]] static bool hasAlternatingBits(int n) {
    bool is_even = n % 2 == 0;
    n /= 2;
    while (n > 0) {
      bool new_is_even = n % 2 == 0;
      if (is_even == new_is_even) {
        return false;
      }
      is_even = new_is_even;
      n /= 2;
    }
    return true;
  }
};