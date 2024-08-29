/* Given an array nums of distinct integers, return all the possible permutations. You can return
the answer in any order.
Time complexity: O(n ^ (n + 1))
Additional memory complexity: O(n)
Idea: use available_numbers array to capture leftmost available number
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        int nums_size = static_cast<int>(nums.size());
        std::vector<std::vector<int>> permutations;
        std::vector<int> curr_perm(nums_size, -11);
        std::vector<bool> available_numbers(nums_size, true);
        getPermutations(permutations, curr_perm, nums, available_numbers, nums_size, 0);
        return permutations;
    }

private:
    static void getPermutations(std::vector<std::vector<int>>& permutations,
                                std::vector<int>& curr_perm, const std::vector<int>& nums,
                                std::vector<bool>& available_numbers, const int& nums_size,
                                int level) {
        if (level == nums_size) {
            permutations.push_back(curr_perm);
            return;
        }
        for (int i = 0; i < nums_size; ++i) {
            if (!available_numbers[i]) {
                continue;
            }
            curr_perm[level] = nums[i];
            available_numbers[i] = false;
            getPermutations(permutations, curr_perm, nums, available_numbers, nums_size, level + 1);
            available_numbers[i] = true;
        }
    }
};

int main() {
    // std::vector<int> nums = {1, 2, 3};
    // std::vector<int> nums = {0, 1};
    std::vector<int> nums = {1};
    std::vector<std::vector<int>> permutations = Solution::permute(nums);
    for (const auto& perm : permutations) {
        for (const auto& num : perm) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
