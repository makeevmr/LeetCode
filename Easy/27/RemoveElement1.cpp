#include <iostream>
#include <vector>

class Solution {
public:
    static int removeElement(std::vector<int> &nums, int val) {
        int non_val_index_push = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[non_val_index_push] = nums[i];
                ++non_val_index_push;
            }
        }
        return non_val_index_push;
    }
};

int main() {
    std::vector<int> nums = {1};
    int val = 1;
    int length = Solution::removeElement(nums, val);
    std::cout << length << std::endl;
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
}
