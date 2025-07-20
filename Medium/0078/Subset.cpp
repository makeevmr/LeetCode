#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    [[nodiscard]] static std::vector<std::vector<int>> subsets(
        const std::vector<int>& nums) {
        int nums_size = static_cast<int>(nums.size());
        std::vector<std::vector<int>> ans;
        ans.reserve(static_cast<int>(std::pow(2, nums_size)));
        const std::vector<int> factorial = calcFactorial();
        for (int i = 0; i <= nums_size; ++i) {
            std::vector<int> curr_subset;
            int index = 0;
            while (index < i) {
                curr_subset.push_back(index++);
            }
            int combinations = factorial[nums_size] /
                               (factorial[nums_size - i] * factorial[i]);
            --combinations;
            pushSubset(ans, curr_subset, nums);
            while (combinations > 0) {
                getNextSubset(curr_subset, nums_size - 1);
                --combinations;
                pushSubset(ans, curr_subset, nums);
            }
        }
        return ans;
    }

private:
    [[nodiscard]] static std::vector<int> calcFactorial() {
        std::vector<int> factorial(11, 1);
        for (int i = 1; i < 11; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        return factorial;
    }

    static void getNextSubset(std::vector<int>& curr_subset, const int& limit) {
        int curr_subset_size = static_cast<int>(curr_subset.size());
        if (curr_subset[curr_subset_size - 1] < limit) {
            ++curr_subset[curr_subset_size - 1];
        } else {
            int break_index = -1;
            for (int i = curr_subset_size - 2; i >= 0; --i) {
                if (curr_subset[i] + 1 < curr_subset[i + 1]) {
                    ++curr_subset[i];
                    break_index = i;
                    break;
                }
            }
            for (int i = break_index + 1; i < curr_subset_size; ++i) {
                curr_subset[i] = curr_subset[i - 1] + 1;
            }
        }
    }

    static void pushSubset(std::vector<std::vector<int>>& subsets,
                           const std::vector<int>& curr_subset,
                           const std::vector<int>& nums) {
        std::vector<int> to_push(curr_subset.size());
        for (std::size_t i = 0; i < curr_subset.size(); ++i) {
            to_push[i] = nums[curr_subset[i]];
        }
        subsets.push_back(std::move(to_push));
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    const auto& ans = Solution::subsets(nums);
    for (const auto& subset : ans) {
        for (const auto& num : subset) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
