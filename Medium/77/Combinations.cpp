/* Given two integers n and k, return all possible combinations of k numbers chosen from the range
[1, n].

You may return the answer in any order.
Time complexity: O(k + (n! * k) / ((n - k)! * k!))
Additional memory complexity: O(k)
Idea: use recursion to calculate all possible combinations
*/

#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> answer;
        std::vector<int> curr_combination(k, -1);
        getAllCombinations(answer, curr_combination, n, k, 0, 1);
        return answer;
    }

private:
    static void getAllCombinations(std::vector<std::vector<int>>& answer,
                                   std::vector<int>& curr_combination, const int& n, const int& k,
                                   int level, int left_border) {
        if (level == k) {
            answer.push_back(curr_combination);
            return;
        }
        for (int i = left_border; i <= n; ++i) {
            curr_combination[level] = i;
            getAllCombinations(answer, curr_combination, n, k, level + 1, i + 1);
        }
    }
};
