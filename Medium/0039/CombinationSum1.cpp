/* Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two
combinations are unique if the frequency of at least one of the chosen numbers
is different.

The test cases are generated such that the number of unique combinations that
sum up to target is less than 150 combinations for the given input. Time
complexity: O(t * 2 ^ t) Additional memory complexity: O(t) Idea: on each step
we either add number to curr_comb from candidates[curr_ind] or move to next
candidate number (++curr_ind)
*/

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    std::vector<int> curr_comb;
    getSumCombinations(candidates, curr_comb, target, 0, 0);
    return answer;
  }

private:
  void getSumCombinations(const std::vector<int>& candidates,
                          std::vector<int>& curr_comb, const int& target,
                          int curr_sum, int curr_ind) {
    if (curr_sum == target) {
      answer.push_back(curr_comb);
      return;
    }
    if (curr_sum > target || curr_ind >= static_cast<int>(candidates.size())) {
      return;
    }
    curr_comb.push_back(candidates[curr_ind]);
    getSumCombinations(candidates, curr_comb, target,
                       curr_sum + candidates[curr_ind], curr_ind);
    curr_comb.pop_back();
    getSumCombinations(candidates, curr_comb, target, curr_sum, curr_ind + 1);
  }

  std::vector<std::vector<int>> answer;
};
