/* You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
represent the start and the end of the ith interval and intervals is sorted in ascending order by
starti. You are also given an interval newInterval = [start, end] that represents the start and end
of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti
and intervals still does not have any overlapping intervals (merge overlapping intervals if
necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.
Time complexity: O(n)
Additional memory: O(1) in good case, O(n) in worst case
Idea: iterate through intervals, merge all overlapping intervals
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                                std::vector<int> &newInterval) {
        int n = intervals.size(), i = 0;
        std::vector<std::vector<int>> res;
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> new_interval = {2, 5};
    // std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    // std::vector<int> new_interval = {4, 8};
    std::vector<std::vector<int>> inserted_intervals = Solution::insert(intervals, new_interval);
    for (const auto &item : inserted_intervals) {
        std::cout << item[0] << ' ' << item[1] << '\n';
    }
    return 0;
}