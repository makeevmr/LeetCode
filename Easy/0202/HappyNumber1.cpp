/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares
of its digits. Repeat the process until the number equals 1 (where it will
stay), or it loops endlessly in a cycle which does not include 1. Those numbers
for which this process ends in 1 are happy. Return true if n is a happy number,
and false if not. Time complexity: O(n) Additional memory complexity: O(1) Idea:
use Floyd's cycle detection algorithm.
*/

#include <iostream>

class Solution {
public:
  static bool isHappy(int n) {
    int slow_pointer = getNewNumber(n);
    int fast_pointer = getNewNumber(getNewNumber(n));
    while (fast_pointer != 1 && fast_pointer != slow_pointer) {
      slow_pointer = getNewNumber(slow_pointer);
      fast_pointer = getNewNumber(getNewNumber(fast_pointer));
    }
    return fast_pointer == 1;
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
  int n = 2;
  std::cout << Solution::isHappy(n) << '\n';
  return 0;
}