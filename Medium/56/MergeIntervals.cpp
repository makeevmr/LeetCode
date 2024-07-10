/* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
Time complexity: O(n * log(n))
Additional memory complexity: O(log(n)) since sort uses QuickSort algorithm
Idea: sort intervals by left border, save current interval and if new interval overlaps previous
than merge them, push previous interval to answer otherwise
*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int> &left, const std::vector<int> &right) {
                      return (left[0] < right[0]) ||
                             ((left[0] == right[0]) && (left[1] < right[1]));
                  });
        std::vector<int> curr_interval = intervals[0];
        std::size_t intervals_size = intervals.size();
        std::vector<std::vector<int>> merged_intervals;
        for (std::size_t i = 1; i < intervals_size; ++i) {
            if (curr_interval[1] >= intervals[i][0]) {
                curr_interval[1] = std::max(curr_interval[1], intervals[i][1]);
            } else {
                merged_intervals.push_back(std::move(curr_interval));
                curr_interval = intervals[i];
            }
        }
        merged_intervals.push_back(std::move(curr_interval));
        return merged_intervals;
    }
};

int main() {
    // std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};
    std::vector<std::vector<int>> merged_intervals = Solution::merge(intervals);
    for (const auto &item : merged_intervals) {
        std::cout << item[0] << ' ' << item[1] << '\n';
    }
    return 0;
}