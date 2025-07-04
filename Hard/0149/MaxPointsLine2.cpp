/* Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return
the maximum number of points that lie on the same straight line.
Time complexity: O(n ^ 3)
Additional memory complexity: O(1)
Idea: compute all possible lines with O(n ^ 2), all points on each line with O(n)
*/

#include <iostream>
#include <vector>

#define EPS 0.000001

class Solution {
public:
    [[nodiscard]] static int maxPoints(const std::vector<std::vector<int>>& points) {
        int points_size = static_cast<int>(points.size());
        if (points_size <= 2) {
            return points_size;
        }
        int max_intersects = 0;
        for (int i = 0; i < points_size - 1; ++i) {
            for (int j = i + 1; j < points_size; ++j) {
                int curr_intersects = 0;
                bool is_first_type = points[i][0] == points[j][0];
                if (!is_first_type) {
                    double k = static_cast<double>(points[i][1] - points[j][1]) /
                               static_cast<double>(points[i][0] - points[j][0]);
                    double b = points[j][1] - k * points[j][0];
                    for (const auto& point : points) {
                        if (std::abs(point[1] - (k * point[0] + b)) < EPS) {
                            ++curr_intersects;
                        }
                    }
                } else {
                    int x = points[i][0];
                    for (const auto& point : points) {
                        if (point[0] == x) {
                            ++curr_intersects;
                        }
                    }
                }
                max_intersects = std::max(max_intersects, curr_intersects);
            }
        }
        return max_intersects;
    }
};

int main() {
    // std::vector<std::vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    std::vector<std::vector<int>> points = {{-6, -1}, {3, 1}, {12, 3}};
    std::cout << Solution::maxPoints(points) << '\n';
    return 0;
}