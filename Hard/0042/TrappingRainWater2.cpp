// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.
// Time complexity: O(n * log(n))
// Additional memory complexity: O(n)
// Idea: sort heights by non-decreasing and use prefix sums

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename K>
class GreaterPairComparator {
public:
    bool operator()(const std::pair<T, K> &left, const std::pair<T, K> &right) {
        return left.first > right.first;
    }
};

class Solution {
public:
    static int trap(const std::vector<int> &height) {
        std::size_t height_size = height.size();
        std::vector<std::pair<int, int>> sorted_heights(height_size, std::pair<int, int>{0, 0});
        std::vector<int> height_prefix_sums(height_size, 0);
        for (std::size_t i = 0; i < height_size; ++i) {
            sorted_heights[i] = {height[i], i};
            height_prefix_sums[i] = height[i];
            if (i > 0) {
                height_prefix_sums[i] += height_prefix_sums[i - 1];
            }
        }
        int total_trapping_water = 0;
        std::sort(sorted_heights.begin(), sorted_heights.end(), GreaterPairComparator<int, int>());
        int left_border = sorted_heights.front().second;
        int right_border = left_border;
        for (std::size_t i = 1; i < height_size; ++i) {
            int max_water_capacity = 0;
            if (sorted_heights[i].second < left_border) {
                max_water_capacity =
                    (left_border - sorted_heights[i].second - 1) * sorted_heights[i].first;
                total_trapping_water += max_water_capacity - height_prefix_sums[left_border - 1] +
                                        height_prefix_sums[sorted_heights[i].second];
                left_border = sorted_heights[i].second;
            }
            if (sorted_heights[i].second > right_border) {
                max_water_capacity =
                    (sorted_heights[i].second - right_border - 1) * sorted_heights[i].first;
                total_trapping_water += max_water_capacity -
                                        height_prefix_sums[sorted_heights[i].second - 1] +
                                        height_prefix_sums[right_border];
                right_border = sorted_heights[i].second;
            }
        }
        return total_trapping_water;
    }
};

int main() {
    // std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    std::cout << Solution::trap(height) << '\n';
    return 0;
}
