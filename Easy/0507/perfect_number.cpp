class Solution {
public:
  [[nodiscard]] static bool checkPerfectNumber(const int& num) {
    if (num == 1) {
      return false;
    }
    int divisors_sum = 1;
    for (int i = 2; i * i <= num; ++i) {
      if (num % i == 0) {
        divisors_sum += i;
        divisors_sum += num / i;
      }
    }
    return num == divisors_sum;
  }
};