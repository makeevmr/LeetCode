/* Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle
which does not include 1. Those numbers for which this process ends in 1 are happy. Return true if n
is a happy number, and false if not.
*/

#include <iostream>
#include <unordered_set>

class Solution {
public:
    static bool isHappy(int n) {
        std::unordered_set<int> used_numbers;
        int curr_number = n;
        do {
            used_numbers.insert(curr_number);
            curr_number = getNewNumber(curr_number);
        } while ((curr_number != 1) && (used_numbers.find(curr_number) == used_numbers.end()));
        return curr_number == 1;
    }

private:
    static int getNewNumber(int number) {
        int result = 0;
        while (number != 0) {
            result += (number % 10) * (number % 10);
            number /= 10;
        }
        return result;
    }
};

int main() {
    int n = 19;
    std::cout << Solution::isHappy(n) << '\n';
    return 0;
}
