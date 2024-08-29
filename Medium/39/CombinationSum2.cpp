/* Given an array of distinct integers candidates and a target integer target, return a list of all
unique combinations of candidates where the chosen numbers sum to target. You may return the
combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are
unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is
less than 150 combinations for the given input.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> curr_combination(candidates.size(), 0);
        std::unordered_set<std::string> used_combinations;
        getSumCombinations(candidates, used_combinations, curr_combination, target);
        return answer;
    }

private:
    void getSumCombinations(const std::vector<int>& candidates,
                            std::unordered_set<std::string>& used_combinations,
                            std::vector<int>& curr_combination, int target) {
        if (target == 0) {
            if (std::string str_combination = toString(curr_combination);
                !used_combinations.contains(str_combination)) {
                answer.push_back(getCombination(candidates, curr_combination));
                used_combinations.insert(str_combination);
            }
            return;
        }
        for (std::size_t i = 0; i < candidates.size(); ++i) {
            if ((target - candidates[i]) >= 0) {
                ++curr_combination[i];
                getSumCombinations(candidates, used_combinations, curr_combination,
                                   target - candidates[i]);
                --curr_combination[i];
            }
        }
    }

    static std::string toString(const std::vector<int>& curr_combination) {
        std::string str_combination;
        for (std::size_t i = 0; i < curr_combination.size(); ++i) {
            str_combination.push_back(curr_combination[i] + 48);
        }
        return str_combination;
    }

    static std::vector<int> getCombination(const std::vector<int>& candidates,
                                           const std::vector<int>& curr_combination) {
        std::vector<int> result;
        for (std::size_t i = 0; i < curr_combination.size(); ++i) {
            for (int j = 0; j < curr_combination[i]; ++j) {
                result.push_back(candidates[i]);
            }
        }
        return result;
    }

    std::vector<std::vector<int>> answer;
};

int main() {
    Solution solution;
    // std::vector<int> candidates = {2, 3, 6, 7};
    // int target = 7;
    // std::vector<int> candidates = {2, 3, 5};
    // int target = 8;
    std::vector<int> candidates = {2};
    int target = 1;
    std::vector<std::vector<int>> answer = solution.combinationSum(candidates, target);
    for (const auto& combination : answer) {
        for (const auto& number : combination) {
            std::cout << number << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
