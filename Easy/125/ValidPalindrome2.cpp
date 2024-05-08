#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
    static bool isPalindrome(const std::string &s) {
        int s_size = static_cast<int>(s.size());
        int left_index = 0;
        int right_index = static_cast<int>(s.size()) - 1;
        while (left_index < right_index) {
            while ((left_index < s_size) && !std::isalnum(s[left_index])) {
                ++left_index;
            }
            while ((right_index >= 0) && (!std::isalnum(s[right_index]))) {
                --right_index;
            }
            if ((left_index < right_index)) {
                if (std::tolower(s[left_index]) != std::tolower(s[right_index])) {
                    return false;
                } else {
                    ++left_index;
                    --right_index;
                }
            }
        }
        return true;
    }
};

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    std::cout << Solution::isPalindrome(s) << std::endl;
    return 0;
}
