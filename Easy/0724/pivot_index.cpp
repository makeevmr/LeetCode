/*
Точка равновесия массива
Дан массив целых чисел. Найдите в нем такой индекс, что сумма элементов слева от
него равна сумме элементов справа от него.


nums = {} -> -1

nums = {5} -> 0

nums = {12, 3, 7, 5}; -> 1

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  static int pivotIndex(const vector<int>& nums) {
    if (nums.empty()) {
      return -1;
    }
    int total_sum = 0;
    for (const int& num : nums) {
      total_sum += num;
    }
    int nums_size = static_cast<int>(nums.size());
    int left_sum = 0;
    int right_sum = total_sum;
    for (int i = 0; i < nums_size; ++i) {
      right_sum -= nums[i];
      if (i > 0) {
        left_sum += nums[i - 1];
      }
      if (left_sum == right_sum) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  // vector<int> nums = {1, 7, 3, 6, 5, 6};  // -> 3
  // vector<int> nums = {1, 2, 3};  // -> -1
  vector<int> nums = {2, 1, -1};  // -> 0
  cout << Solution::pivotIndex(nums) << '\n';
  return 0;
}
