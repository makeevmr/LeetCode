#include <iostream>
#include <vector>

class Solution {
public:
    static int jump(std::vector<int> &nums) {
        int jumps_count = 0;
        int current_index = 0;
        int nums_last_index = static_cast<int>(nums.size()) - 1;
        while (current_index < nums_last_index) {
            if ((current_index + nums[current_index]) >= nums_last_index) {
                ++jumps_count;
                current_index = nums_last_index;
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
                ++jumps_count;
                current_index = index_to_jump;
            }
        }
        return jumps_count;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 0, 1, 4};
    std::cout << Solution::jump(nums) << std::endl;
    return 0;
}
