/* You are given a string s.
You can perform the following process on s any number of times:
Choose an index i in the string such that there is at least one character to the left of index i
that is equal to s[i], and at least one character to the right that is also equal to s[i]. Delete
the closest character to the left of index i that is equal to s[i]. Delete the closest character to
the right of index i that is equal to s[i]. Return the minimum length of the final string s that you
can achieve.
Time complexity: O(n)
Additional memory complexity: O(size of alphabet)
Idea: store frequency of each symbol in unordered_map
*/

#include <iostream>
#include <string>
#include <unordered_map>

using ull = unsigned long long int;
using ll = long long int;

class Solution {
public:
    static int minimumLength(const std::string &s) {
        std::unordered_map<char, int> symbol_freq;
        for (const char &symbol : s) {
            ++symbol_freq[symbol];
        }
        int answer = 0;
        for (auto &[symbol, freq] : symbol_freq) {
            if (freq % 2 == 0) {
                answer += 2;
            } else {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
    std::string s = "aa";
    std::cout << Solution::minimumLength(s) << '\n';
    return 0;
}
