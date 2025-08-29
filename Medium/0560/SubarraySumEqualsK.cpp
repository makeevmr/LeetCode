/* Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k. A subarray is a contiguous non-empty sequence
of elements within an array. Time complexity: O(n) Additional memory complexity:
O(n) Idea: use hashmap of prefix sums which was met on previous steps (key =
sum, value = number of prefix sums), k = curr_pref_sum - prev_prefix_sum, than
prev_prefix_sum = curr_pref_sum - k;
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
  [[nodiscard]] static int subarraySum(const std::vector<int>& nums, int k) {
    int answer = 0;
    int pref_sum = 0;
    std::unordered_map<int, int> pref_sums_counts = {{0, 1}};
    for (std::size_t i = 0, nums_size = nums.size(); i < nums_size; ++i) {
      pref_sum += nums[i];
      if (pref_sums_counts.contains(pref_sum - k)) {
        answer += pref_sums_counts[pref_sum - k];
      }
      ++pref_sums_counts[pref_sum];
    }
    return answer;
  }
};
