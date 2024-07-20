/* You are given two positive integers x and y, denoting the number of coins with values 75 and 10
respectively.
Alice and Bob are playing a game. Each turn, starting with Alice, the player must pick up coins with
a total value 115. If the player is unable to do so, they lose the game.
Return the name of the player who wins the game if both players play optimally.
Time complexity: O(1)
Additional memory complexity: O(1)
Idea: min(x, y / 4)
*/

#include <bits/stdc++.h>
using ull = unsigned long long int;
using ll = long long int;

using namespace std;

class Solution {
public:
    static string losingPlayer(int x, int y) {
        int total_turns = std::min(x, y / 4);
        if (total_turns % 2 == 1) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};

int main() {
    std::cout << Solution::losingPlayer(2, 7) << '\n';
    std::cout << Solution::losingPlayer(4, 11) << '\n';
    return 0;
}
