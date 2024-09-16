/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
Time complexity: O(n)
Additional memory complexity: O(log(n))
Idea: use quickselect Tony Hoare's algorithm
*/

#include <iostream>
#include <ctime>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int findKthLargest(std::vector<int>& nums, int k) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int nums_size = static_cast<int>(nums.size());
        int order_stat = nums_size + 1 - k;
        std::pair<int, int> partition_pair = {-1, -1};
        int left = 0;
        int right = nums_size - 1;
        while (true) {
            partition_pair = partition(nums, left, right);
            if (partition_pair.first <= order_stat && order_stat <= partition_pair.second) {
                break;
            }
            if (order_stat < partition_pair.first) {
                right = partition_pair.first + left - 2;
            } else {
                order_stat -= partition_pair.second;
                left = partition_pair.second + left;
            }
        }
        return nums[left + order_stat - 1];
    }

private:
    [[nodiscard]] static std::pair<int, int> partition(std::vector<int>& nums, int l, int r) {
        int l_pivot_ind = l + std::rand() % (r - l + 1);
        std::swap(nums[l], nums[l_pivot_ind]);
        l_pivot_ind = l;
        int r_pivot_ind = l_pivot_ind;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] == nums[l_pivot_ind]) {
                ++r_pivot_ind;
                std::swap(nums[i], nums[r_pivot_ind]);
            }
            if (nums[i] < nums[l_pivot_ind]) {
                std::swap(nums[i], nums[l_pivot_ind]);
                ++l_pivot_ind;
                ++r_pivot_ind;
                std::swap(nums[i], nums[r_pivot_ind]);
            }
        }
        return std::pair<int, int>{l_pivot_ind - l + 1, r_pivot_ind - l + 1};
    }
};

int main() {
    // std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    // int k = 2;
    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    // std::vector<int> nums = {3, 3, 3, 3, 4, 3, 3, 3, 3};
    // int k = 5;
    std::cout << Solution::findKthLargest(nums, k) << '\n';
    return 0;
}