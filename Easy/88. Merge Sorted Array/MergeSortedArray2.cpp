#include <iostream>
#include <vector>

class Solution {
public:
    static void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        int nums1_index = 0;
        int nums2_index = 0;
        int additional_buffer_index = 0;
        std::vector<int> additional_buffer;
        while ((nums1_index < m) && (nums2_index < n)) {
            if ((nums1[nums1_index] <= nums2[nums2_index]) &&
                ((additional_buffer.size() == 0) ||
                 (additional_buffer_index < additional_buffer.size()) &&
                     (nums1[nums1_index] <= additional_buffer[additional_buffer_index]))) {
                ++nums1_index;
                continue;
            } else if (additional_buffer_index < additional_buffer.size() &&
                       additional_buffer[additional_buffer_index] < nums1[nums1_index] &&
                       additional_buffer[additional_buffer_index] <= nums2[nums2_index]) {
                additional_buffer.push_back(nums1[nums1_index]);
                nums1[nums1_index] = additional_buffer[additional_buffer_index];
                ++additional_buffer_index;
            } else {
                std::swap(nums1[nums1_index], nums2[nums2_index]);
                if ((nums2_index != n - 1) && (nums2[nums2_index] > nums2[nums2_index + 1])) {
                    additional_buffer.push_back(nums2[nums2_index]);
                    ++nums2_index;
                }
            }
            ++nums1_index;
        }
        size_t additional_buffer_size = additional_buffer.size();
        while ((nums2_index < n) && (additional_buffer_index < additional_buffer_size)) {
            if (nums2[nums2_index] < additional_buffer[additional_buffer_index]) {
                nums1[nums1_index] = nums2[nums2_index];
                ++nums2_index;
            } else {
                nums1[nums1_index] = additional_buffer[additional_buffer_index];
                ++additional_buffer_index;
            }
            ++nums1_index;
        }
        while (additional_buffer_index < additional_buffer_size) {
            nums1[nums1_index] = additional_buffer[additional_buffer_index];
            ++additional_buffer_index;
            ++nums1_index;
        }
        while (nums2_index < n) {
            nums1[nums1_index] = nums2[nums2_index];
            ++nums2_index;
            ++nums1_index;
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    Solution::merge(nums1, static_cast<int>(nums1.size() - nums2.size()), nums2, static_cast<int>(nums2.size()));
    for (int i = 0; i < nums1.size(); ++i) {
        std::cout << nums1[i] << ' ';
    }
    return 0;
}
