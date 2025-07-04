/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the
two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Time complexity: O(log(m + n))
Additional memory complexity: O(1)
Idea: use binary search by answer as outer loop in nums1 than find that number in nums2 in inner
loop
*/

#include <iostream>
#include <vector>

class Solution {
public:
    [[nodiscard]] double findMedianSortedArrays(const std::vector<int>& nums1,
                                                const std::vector<int>& nums2) {
        if (nums1.empty()) {
            if (nums2.size() % 2 != 0) {
                return nums2[nums2.size() / 2];
            } else {
                return (static_cast<double>(nums2[nums2.size() / 2] +
                                            static_cast<double>(nums2[(nums2.size() / 2) - 1]))) /
                       2.0;
            }
        }
        if (nums2.empty()) {
            if (nums1.size() % 2 != 0) {
                return nums1[nums1.size() / 2];
            } else {
                return (static_cast<double>(nums1[nums1.size() / 2] +
                                            static_cast<double>(nums1[nums1.size() / 2 - 1]))) /
                       2.0;
            }
        }
        int nums1_size = static_cast<int>(nums1.size());
        int nums2_size = static_cast<int>(nums2.size());
        if ((nums1_size + nums2_size) % 2 != 0) {
            int answer = findKStatistic(nums1, nums2, (nums1_size + nums2_size - 1) / 2);
            if (answer == -1) {
                answer = findKStatistic(nums2, nums1, (nums1_size + nums2_size - 1) / 2);
            }
            return static_cast<double>(answer);
        } else {
            int k2 = (nums1_size + nums2_size) / 2;
            int k1 = k2 - 1;
            int answer1 = findKStatistic(nums1, nums2, k1);
            int answer2 = findKStatistic(nums1, nums2, k2);
            if (answer1 == -1) {
                answer1 = findKStatistic(nums2, nums1, k1);
            }
            if (answer2 == -1) {
                answer2 = findKStatistic(nums2, nums1, k2);
            }
            return (static_cast<double>(answer1) + static_cast<double>(answer2)) / 2.0;
        }
    }

private:
    [[nodiscard]] int static findKStatistic(const std::vector<int>& nums1,
                                            const std::vector<int>& nums2, int k) {
        int left1 = 0;
        int right1 = static_cast<int>(nums1.size()) - 1;
        while (left1 < right1) {
            int middle1 = (left1 + right1) >> 1;
            int left2 = leftBinarySearch(nums2, nums1[middle1]);
            int right2 = rightBinarySearch(nums2, nums1[middle1]);
            int min_statistic = middle1 + left2;
            int max_statistic =
                right2 < static_cast<int>(nums2.size()) && nums2.at(right2) == nums1.at(middle1)
                    ? middle1 + right2 + 1
                    : middle1 + right2;
            if (min_statistic <= k && k <= max_statistic) {
                return nums1[middle1];
            }
            if (min_statistic > k) {
                right1 = middle1;
            } else {
                left1 = middle1 + 1;
            }
        }
        int left2 = leftBinarySearch(nums2, nums1[left1]);
        int right2 = rightBinarySearch(nums2, nums1[left1]);
        int min_statistic = left1 + left2;
        int max_statistic =
            right2 < static_cast<int>(nums2.size()) && nums2.at(right2) == nums1.at(left1)
                ? left1 + right2 + 1
                : left1 + right2;
        if (min_statistic <= k && k <= max_statistic) {
            return nums1[left1];
        } else {
            return -1;
        }
    }

    [[nodiscard]] static int leftBinarySearch(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int middle = (left + right) >> 1;
            if (nums[middle] >= target) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        if (nums[left] < target) {
            ++left;
        }
        return left;
    }

    [[nodiscard]] static int rightBinarySearch(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());
        while (left < right - 1) {
            int middle = (left + right) >> 1;
            if (nums[middle] > target) {
                right = middle;
            } else {
                left = middle;
            }
        }
        if (nums[left] < target) {
            ++left;
        }
        return left;
    }
};
