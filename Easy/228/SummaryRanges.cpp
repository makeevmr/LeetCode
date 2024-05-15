#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static std::vector<std::string> summaryRanges(const std::vector<int> &nums) {
        std::size_t nums_size = nums.size();
        int left_border = nums_size > 0 ? nums[0] : 0;
        bool is_left_set = false;
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
    for (const auto &range : answer) {
        std::cout << range << '\n';
    }
    return 0;
}
