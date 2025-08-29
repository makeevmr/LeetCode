// Given a string s, partition s such that every substring of the partition is a
// palindrome. Return all possible palindrome partitioning of s.

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<std::string>> partition(
      const std::string& s) {
    const std::vector<std::vector<bool>> is_pali_matrix =
        createPalindromeMatrix(s);
    int s_size = static_cast<int>(s.size());
    std::vector<std::vector<std::string>> partitions;
    std::vector<std::pair<int, int>> curr_partition;
    std::pair<int, int> curr_substr = {0, 0};
    getPartitions(partitions, s, curr_partition, is_pali_matrix, curr_substr,
                  s_size);
    return partitions;
  }

private:
  [[nodiscard]] static std::vector<std::vector<bool>> createPalindromeMatrix(
      const std::string& s) {
    int s_size = static_cast<int>(s.size());
    std::vector<std::vector<bool>> is_pali_matrix(
        s_size, std::vector<bool>(s_size, false));
    for (int i = 0; i < s_size; ++i) {
      is_pali_matrix[i][i] = true;
    }
    for (int j = 1; j < s_size; ++j) {
      for (int i = j - 1; i >= 0; --i) {
        bool is_pali = s[i] == s[j];
        if ((j - i >= 2) && is_pali) {
          is_pali = is_pali_matrix[i + 1][j - 1];
        }
        is_pali_matrix[i][j] = is_pali;
      }
    }
    return is_pali_matrix;
  }

  static void getPartitions(
      std::vector<std::vector<std::string>>& partitions, const std::string& s,
      std::vector<std::pair<int, int>>& curr_partition,
      const std::vector<std::vector<bool>>& is_pali_matrix,
      std::pair<int, int>& curr_substr, const int& s_size) {
    bool is_pali_substr = is_pali_matrix[curr_substr.first][curr_substr.second];
    if (curr_substr.second + 1 == s_size) {
      if (is_pali_substr) {
        curr_partition.push_back(curr_substr);
        fillPartition(partitions, s, curr_partition);
        curr_partition.pop_back();
      }
      return;
    }
    if (is_pali_substr) {
      curr_partition.push_back(curr_substr);
      curr_substr = {curr_substr.second + 1, curr_substr.second + 1};
      getPartitions(partitions, s, curr_partition, is_pali_matrix, curr_substr,
                    s_size);
      curr_substr = curr_partition.back();
      curr_partition.pop_back();
    }
    ++curr_substr.second;
    getPartitions(partitions, s, curr_partition, is_pali_matrix, curr_substr,
                  s_size);
    --curr_substr.second;
  }

  static void fillPartition(
      std::vector<std::vector<std::string>>& partitions, const std::string& s,
      const std::vector<std::pair<int, int>>& curr_partition) {
    std::vector<std::string> new_partition;
    for (const auto& [left, right] : curr_partition) {
      new_partition.push_back(s.substr(left, right - left + 1));
    }
    partitions.push_back(std::move(new_partition));
  }
};

int main() {
  std::string s = "aab";
  std::vector<std::vector<std::string>> partitions = Solution::partition(s);
  for (const auto& paritiion : partitions) {
    for (const auto& substr : paritiion) {
      std::cout << substr << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
