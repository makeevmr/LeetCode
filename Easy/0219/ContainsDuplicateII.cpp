/* Given an integer array nums and an integer k, return true if there are two distinct indices i and
j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Time complexity: O(n)
Additional memory complexity: O(n)
Idea: use unordered_map to store last occurrences of each element (number, index)
*/

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    static bool containsNearbyDuplicate(const std::vector<int> &nums, int k) {
        std::size_t distance = static_cast<std::size_t>(k);
        std::unordered_map<int, std::size_t> last_occurrences;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (auto f_iter = last_occurrences.find(nums[i]); f_iter == last_occurrences.end()) {
                last_occurrences.insert({nums[i], i});
            } else if (i - f_iter->second <= distance) {
                return true;
            } else {
                f_iter->second = i;
            }
        }
        return false;
    }
};

int main() {
    // std::vector<int> nums = {1, 2, 3, 1};
    // int k = 3;
    // std::vector<int> nums = {1, 0, 1, 1};
    // int k = 1;
    std::vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;
    std::cout << Solution::containsNearbyDuplicate(nums, k) << '\n';
    return 0;
}
