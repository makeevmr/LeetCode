/* Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return
the maximum number of points that lie on the same straight line.
Time complexity: O(n ^ 2)
Additional memory complexity: O(n)
Idea: fix one point, compute all inclines of all line with this fixed point and store them in
hashmap
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    [[nodiscard]] static int maxPoints(const std::vector<std::vector<int>>& points) {
        int points_size = static_cast<int>(points.size());
        int answer = 1;
        std::unordered_map<int, std::unordered_map<int, int>> inclines_map;
        for (int i = 0; i < points_size; ++i) {
            inclines_map.clear();
            for (int j = i + 1; j < points_size; ++j) {
                int incline_numer = points[i][1] - points[j][1];
                int incline_denom = points[i][0] - points[j][0];
                // if factor is neg, than neg number in numerator
                if (incline_numer >= 0 && incline_denom < 0) {
                    incline_numer *= -1;
                    incline_denom *= -1;
                }
                int factor_gcd = gcd(incline_numer, incline_denom);
                incline_numer /= factor_gcd;
                incline_denom /= factor_gcd;
                ++inclines_map[incline_numer][incline_denom];
                answer = std::max(answer, inclines_map[incline_numer][incline_denom] + 1);
            }
        }
        return answer;
    }

private:
    [[nodiscard]] static int gcd(int left, int right) {
        while (right != 0) {
            left %= right;
            std::swap(left, right);
        }
        return left;
    }
};