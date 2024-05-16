#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Solution {
public:
    static int lengthOfLIS(std::vector<int> &nums) {
        std::vector<int> answer;
        std::size_t nums_size = nums.size();
        answer.push_back(nums[0]);
        for (std::size_t i = 1; i < nums_size; ++i) {
            if (answer.back() < nums[i]) {
                answer.push_back(nums[i]);
            } else {
                // int left_border =
                //     lower_bound(answer.begin(), answer.end(), nums[i]) - answer.begin();
                int left_border = 0;
                int right_border = static_cast<int>(answer.size()) - 1;
                while (left_border < right_border) {
                    int middle = (left_border + right_border) >> 1;
                    if (answer[middle] >= nums[i]) {
                        right_border = middle;
                    } else {
                        left_border = middle + 1;
                    }
                }
                answer[left_border] = nums[i];
            }
        }
        return static_cast<int>(answer.size());
    }
};

int main() {
    // std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // std::vector<int> nums = {0, 1, 0, 3, 2, 3};
    // std::vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    std::vector<int> nums = {10, 9, 2, 5, 3, 4};
    std::cout << Solution::lengthOfLIS(nums) << '\n';
    return 0;
}
