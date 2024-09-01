/* You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is,
each element of nums is covered by exactly one of the ranges, and there is no integer x such that x
is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b
Time complexity: O(n)
Additional memory complexiy: O(1)
Idea: iterate through nums and store all intervals
*/
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
        std::size_t nums_size = nums.size();
        int left_border = nums_size > 0 ? nums[0] : 0;
        std::vector<std::string> answer;
        for (std::size_t i = 1; i < nums_size; ++i) {
            if ((static_cast<long long int>(nums[i]) - static_cast<long long int>(nums[i - 1])) >
                1) {
                if (left_border == nums[i - 1]) {
                    answer.push_back(std::to_string(left_border));
                } else {
                    answer.push_back(std::to_string(left_border) + "->" +
                                     std::to_string(nums[i - 1]));
                }
                left_border = nums[i];
            }
        }
        if (nums.size() > 0) {
            if (left_border == nums.back()) {
                answer.push_back(std::to_string(left_border));
            } else {
                answer.push_back(std::to_string(left_border) + "->" + std::to_string(nums.back()));
            }
        }
        return answer;
    }
};

int main() {
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    // std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    std::vector<std::string> answer = Solution::summaryRanges(nums);
    for (const auto& range : answer) {
        std::cout << range << '\n';
    }
    return 0;
}
