/* There are some spherical balloons taped onto a flat wall that represents the XY-plane. The
balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a
balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact
y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along
the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend.
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up
infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
Time complexity: O(n * log(n))
Additional memory complexity: O(log(n)) since std::sort use QuickSort implementation
Idea: sort intervals by left[0] < right[0], if equals then left[1] > right[1], iterate through
points calculate number of intersections
*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static int findMinArrowShots(std::vector<std::vector<int>> &points) {
        std::sort(points.begin(), points.end(),
                  [](const std::vector<int> &left, const std::vector<int> &right) {
                      return (left[0] < right[0]) ||
                             ((left[0] == right[0]) && (left[1] > right[1]));
                  });
        std::size_t points_size = points.size();
        int arrows_amount = 1;
        std::vector<int> curr_interval = std::move(points[0]);
        for (std::size_t i = 1; i < points_size; ++i) {
            if (points[i][0] <= curr_interval[1]) {
                curr_interval[0] = points[i][0];
                curr_interval[1] = std::min(points[i][1], curr_interval[1]);
            } else {
                ++arrows_amount;
                curr_interval = std::move(points[i]);
            }
        }
        return arrows_amount;
    }
};

int main() {
    // std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    // std::vector<std::vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    std::vector<std::vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    std::cout << Solution::findMinArrowShots(points) << '\n';
    return 0;
}
