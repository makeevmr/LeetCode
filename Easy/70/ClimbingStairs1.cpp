/* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: use Fibonacci sequence
*/

#include <vector>

class Solution {
public:
    [[nodiscard]] static int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        n -= 2;
        while (n-- > 0) {
            int tmp = second;
            second += first;
            first = tmp;
        }
        return second;
    }
};