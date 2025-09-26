#include <vector>

class Solution {
public:
  [[nodiscard]] static int numOfSubarrays(const std::vector<int>& arr) {
    int answer = 0;
    int even_sums_counter = 1;
    int odd_sums_counter = 0;
    int curr_sum = 0;
    for (const int& num : arr) {
      curr_sum += num;
      if (curr_sum % 2 == 0) {
        answer = (answer + odd_sums_counter) % kMod;
        ++even_sums_counter;
      } else {
        answer = (answer + even_sums_counter) % kMod;
        ++odd_sums_counter;
      }
    }
    return answer;
  }

private:
  static constexpr int kMod = 1'000'000'007;
};