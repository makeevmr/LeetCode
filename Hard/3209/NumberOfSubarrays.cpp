/* Given an array of integers nums and an integer k, return the number of subarrays
 of nums where the bitwise AND of the elements of the subarray equals k.
 Time complexity: O(n * 32) = O(n), where n is size of nums array
 Additional memory complexity: O(1)
 Idea: use two pointers to store current subarray, use array of 32 elements to store number of
 occurances of each bit in subarray, count subarrays with number >= k and count subarrays with
 number >= k + 1
 */

#include <array>
#include <iostream>
#include <vector>

class Solution {
public:
    static long long countSubarrays(std::vector<int> &nums, int k) {
        return countAtLeastSubarrays(nums, k) - countAtLeastSubarrays(nums, k + 1);
    }

private:
    static const int bits_amount = 32;

    static long long countAtLeastSubarrays(const std::vector<int> &nums, int k) {
        std::array<u_int32_t, bits_amount> bits_counter = {0};
        long long int at_least_counter = 0;
        int curr_number = -1;
        int left = -1;
        int nums_size = static_cast<int>(nums.size());
        for (int i = 0; i < nums_size; ++i) {
            curr_number &= nums[i];
            addToBitsCounter(bits_counter, nums[i]);
            while ((left < i) && (curr_number < k)) {
                ++left;
                removeFromBitsCounter(bits_counter, nums[left]);
                curr_number = setNumber(bits_counter);
            }
            at_least_counter += i - left;
        }
        return at_least_counter;
    }

    [[nodiscard]] static int setNumber(const std::array<u_int32_t, bits_amount> &bits_counter) {
        int result = 0;
        for (int i = 0; i < bits_amount; ++i) {
            if (bits_counter[bits_amount - i - 1] == 0) {
                result |= (1 << i);
            }
        }
        return result;
    }

    static void addToBitsCounter(std::array<u_int32_t, bits_amount> &bits_counter, int number) {
        for (int i = 0; i < bits_amount; ++i) {
            if (!(number & (1 << i))) {
                ++bits_counter[bits_amount - i - 1];
            }
        }
    }

    static void removeFromBitsCounter(std::array<u_int32_t, bits_amount> &bits_counter,
                                      int number) {
        for (int i = 0; i < bits_amount; ++i) {
            if (!(number & (1 << i))) {
                --bits_counter[bits_amount - i - 1];
            }
        }
    }
};

int main() {
    // std::vector<int> nums = {1, 1, 1};
    // int k = 1;
    // std::vector<int> nums = {1, 1, 2};
    // int k = 1;
    std::vector<int> nums = {1, 2, 3};
    int k = 2;
    std::cout << Solution::countSubarrays(nums, k) << '\n';
    return 0;
}
