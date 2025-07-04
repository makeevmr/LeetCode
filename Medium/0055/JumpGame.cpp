#include <iostream>
#include <vector>

class Solution {
public:
    static bool canJump(std::vector<int> &nums) {
        int current_index = 0;
        while ((nums[current_index] != 0) && (current_index < (nums.size() - 1))) {
            if ((current_index + nums[current_index]) >= (nums.size() - 1)) {
                current_index = static_cast<int>(nums.size() - 1);
            } else {
                int index_to_jump = current_index + nums[current_index];
                int steps_count = 0;
                for (int i = current_index + 1; i <= current_index + nums[current_index]; ++i) {
                    int new_steps_count = nums[i] + i - current_index - nums[current_index];
                    if (new_steps_count > steps_count) {
                        steps_count = new_steps_count;
                        index_to_jump = i;
                    }
                }
                current_index = index_to_jump;
            }
        }
        if (current_index == (nums.size() - 1)) {
            return true;
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {3, 0, 8, 2, 0, 0, 1};
    std::cout << Solution::canJump(nums) << std::endl;
    return 0;
}
