/* Given an integer x, return true if x is a palindrome, and false otherwise.
Time complexity: O(x_size)
Additional memory complexity: O(x_size)
Idea: create x_str and x_reverse_str and compare them
*/

#include <string>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] static bool isPalindrome(int x) {
        std::string x_str = std::to_string(x);
        std::string x_reverse_str = x_str;
        std::reverse(x_reverse_str.begin(), x_reverse_str.end());
        return x_str == x_reverse_str;
    }
};