/* Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: count 5 factors in n!
*/

class Solution {
public:
    [[nodiscard]] static int trailingZeroes(int n) {
        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            answer += factorFiveCount(i);
        }
        return answer;
    }

private:
    [[nodiscard]] static int factorFiveCount(int n) {
        if (n == 0) {
            return 0;
        }
        int counter = 0;
        while (n % 5 == 0) {
            ++counter;
            n /= 5;
        }
        return counter;
    }
};