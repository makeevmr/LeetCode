#include <vector>
#include <string>
#include <algorithm>
#include <array>

class Solution {
private:
  struct LCPVecValue;

public:
  [[nodiscard]] static std::vector<int> longestCommonPrefix(
      const std::vector<std::string>& words) {
    const int words_size = static_cast<int>(words.size());
    if (words_size == 1) {
      return std::vector<int>{0};
    }
    if (words_size == 2) {
      return std::vector<int>{0, 0};
    }
    const std::array<LCPVecValue, 3> max_lcp_values_dist1 =
        getThreeMaxLCPValues(getLongestCommonPrefixVec(words, 1));
    const std::vector<int>& lcp_vec_dist2 = getLongestCommonPrefixVec(words, 2);
    std::vector<int> answer;
    answer.reserve(words_size);
    for (int i = 0; i < words_size; ++i) {
      int j1 = 0;
      while ((max_lcp_values_dist1[j1].ind_ == i) ||
             (max_lcp_values_dist1[j1].ind_ + 1 == i)) {
        ++j1;
      }
      int new_answer = max_lcp_values_dist1[j1].value_;
      if (i != 0 && i != words_size - 1) {
        new_answer = std::max(new_answer, lcp_vec_dist2[i - 1]);
      }
      answer.push_back(new_answer);
    }
    return answer;
  }

private:
  [[nodiscard]] static int getLongestCommonPrefix(const std::string& s1,
                                                  const std::string& s2) {
    const std::size_t s1_size = s1.size();
    const std::size_t s2_size = s2.size();
    const std::size_t min_size = std::min(s1_size, s2_size);
    std::size_t lcp_size = 0;
    while (lcp_size < min_size && s1[lcp_size] == s2[lcp_size]) {
      ++lcp_size;
    }
    return static_cast<int>(lcp_size);
  }

  [[nodiscard]] static std::vector<int> getLongestCommonPrefixVec(
      const std::vector<std::string>& words, int dist) {
    std::vector<int> lcp_vec(words.size() - dist, 0);
    for (std::size_t i = 0; i < lcp_vec.size(); ++i) {
      lcp_vec[i] = getLongestCommonPrefix(words[i], words[i + dist]);
    }
    return lcp_vec;
  }

  static std::array<LCPVecValue, 3> getThreeMaxLCPValues(
      const std::vector<int>& lcp_vec) {
    std::array<LCPVecValue, 3> max_lcp_values = {
        LCPVecValue{-1, -1}, LCPVecValue{-1, -1}, LCPVecValue{-1, -1}};
    const int lcp_vec_size = static_cast<int>(lcp_vec.size());
    for (int i = 0; i < lcp_vec_size; ++i) {
      if (lcp_vec[i] > max_lcp_values[0].value_) {
        max_lcp_values[2] = max_lcp_values[1];
        max_lcp_values[1] = max_lcp_values[0];
        max_lcp_values[0] = LCPVecValue{.value_ = lcp_vec[i], .ind_ = i};
      } else if (lcp_vec[i] > max_lcp_values[1].value_) {
        max_lcp_values[2] = max_lcp_values[1];
        max_lcp_values[1] = LCPVecValue{.value_ = lcp_vec[i], .ind_ = i};
      } else if (lcp_vec[i] > max_lcp_values[2].value_) {
        max_lcp_values[2] = LCPVecValue{.value_ = lcp_vec[i], .ind_ = i};
      }
    }
    return max_lcp_values;
  }

  struct LCPVecValue {
    int value_;
    int ind_;
  };
};

#include <iostream>

int main() {
  std::vector<std::string> words = {"cdbff"};
  const std::vector<int>& ans = Solution::longestCommonPrefix(words);
  std::for_each(ans.begin(), ans.end(), [](const int& val) {
    std::cout << val << ' ';
  });
  std::cout << '\n';
  return 0;
}