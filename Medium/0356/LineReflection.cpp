/* Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects
the given points symmetrically.

In other words, answer whether or not if there exists a line that after reflecting all points over
the given line, the original points' set is the same as the reflected ones.

Note that there can be repeated points.
Time complexity: O(n)
Additional memory complexity: O(n)
Idea: search point with mix_x and with max_x, than line_x = (mix_x + max_x) / 2;
Store all points in hashtable to solve problem in O(n)
*/

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    [[nodiscard]] static bool isReflected(std::vector<std::vector<int>>& points) {
        int min_x = std::numeric_limits<int>::max();
        int max_x = std::numeric_limits<int>::min();
        std::unordered_map<int, std::unordered_set<int>> points_map;
        for (std::size_t i = 0, points_size = points.size(); i < points_size; ++i) {
            min_x = std::min(points[i][0], min_x);
            max_x = std::max(points[i][0], max_x);
            points_map[points[i][0]].insert(points[i][1]);
        }
        int sum = min_x + max_x;
        for (auto b_iter = points_map.begin(), e_iter = points_map.end(); b_iter != e_iter;
             ++b_iter) {
            for (const int& y_coord : b_iter->second) {
                if (!points_map.contains(sum - b_iter->first) ||
                    !points_map[sum - b_iter->first].contains(y_coord)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::vector<int>> points = {{1, 1}, {-1, 1}};
    // std::vector<std::vector<int>> points = {{1, 1}, {-1, -1}};
    std::cout << Solution::isReflected(points) << '\n';
    return 0;
}