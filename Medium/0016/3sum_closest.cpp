/*
Дан массив целых чисел nums и целое число target. Нужно найти такую тройку
чисел в массиве с различными индексами, что их сумма наиболее близка к target.
Вывести необходимо сумму трех чисел.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int nums_size = static_cast<int>(nums.size());
    int answer = 0;
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i < nums_size - 2; ++i) {
      int j = i + 1;
      int k = nums_size - 1;
      int curr_target_sum = nums[i] + nums[j] + nums[k];
      if (curr_target_sum == target) {
        return target;
      }
      if (min_diff > abs(target - curr_target_sum)) {
        min_diff = abs(target - curr_target_sum);
        answer = curr_target_sum;
      }
      while (j + 1 < k) {
        if (curr_target_sum > target) {
          --k;
        }
        if (curr_target_sum < target) {
          ++j;
        }
        curr_target_sum = nums[i] + nums[j] + nums[k];
        if (curr_target_sum == target) {
          return target;
        }
        if (min_diff > abs(target - curr_target_sum)) {
          min_diff = abs(target - curr_target_sum);
          answer = curr_target_sum;
        }
      }
    }
    return answer;
  }
};
