/* There is a robot on an m x n grid. The robot is initially located at the
top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right
corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right
at any point in time.

Given the two integers m and n, return the number of possible unique paths that
the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2
* 109. */

#include <vector>

class Solution {
public:
    [[nodiscard]] static int uniquePaths(const int& m, const int& n) {
        std::vector<int> unique_paths(n, 1);
        for (int _ = 1; _ < m; ++_) {
            for (int i = 1; i < n; ++i) {
                unique_paths[i] += unique_paths[i - 1];
            }
        }
        return unique_paths.back();
    }
};
