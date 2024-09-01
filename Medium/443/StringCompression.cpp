/* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input
character array chars. Note that group lengths that are 10 or longer will be split into multiple
characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: iterate through array from left to right, use read and write pointers
*/

#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int chars_size = static_cast<int>(chars.size());
        int read_ind = 0;
        int write_ind = 0;
        char curr_symbol = 0;
        int counter = 0;
        while (read_ind < chars_size) {
            curr_symbol = chars[read_ind];
            while ((read_ind < chars_size) && (curr_symbol == chars[read_ind])) {
                ++read_ind;
                ++counter;
            }
            chars[write_ind++] = curr_symbol;
            if (counter > 1) {
                int digits_counter = 0;
                int base = 1;
                while (counter >= base) {
                    ++digits_counter;
                    base *= 10;
                }
                for (int i = write_ind + digits_counter - 1; i >= write_ind; --i) {
                    chars[i] = counter % 10 + 48;
                    counter /= 10;
                }
                write_ind += digits_counter;
            }
            counter = 0;
        }
        while (write_ind < chars_size) {
            chars.pop_back();
            ++write_ind;
        }
        return static_cast<int>(chars.size());
    }
};

int main() {
    return 0;
}
