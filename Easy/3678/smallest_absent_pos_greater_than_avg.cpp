#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int smallestAbsent(const std::vector<int>& nums) {
    std::unordered_set<int> nums_set;
    int sum = 0;
    for (const int& num : nums) {
      sum += num;
      nums_set.insert(num);
    }
    double avg = static_cast<double>(sum) / nums.size();
    int int_avg = static_cast<int>(avg);
    ++int_avg;
    int_avg = std::max(int_avg, 1);
    while (nums_set.contains(int_avg)) {
      ++int_avg;
    }
    return int_avg;
  }
};