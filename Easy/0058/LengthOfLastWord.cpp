// Given a string s consisting of words and spaces, return the length of the last word in the
// string.

#include <iomanip>
#include <iostream>
#include <string>

class Solution {
public:
    static int lengthOfLastWord(std::string s) {
        int curr_index = static_cast<int>(s.size()) - 1;
        while (s[curr_index] == ' ') {
            --curr_index;
        }
        int last_word_lenght = 0;
        while ((curr_index >= 0) && (std::isalpha(s[curr_index]))) {
            ++last_word_lenght;
            --curr_index;
        }
        return last_word_lenght;
    }
};

int main() {
    // std::string input_str = "Hello World";
    // std::string input_str = "   fly me   to   the moon  ";
    std::string input_str = "luffy is still joyboy";
    std::cout << Solution::lengthOfLastWord(input_str) << '\n';
    return 0;
}
