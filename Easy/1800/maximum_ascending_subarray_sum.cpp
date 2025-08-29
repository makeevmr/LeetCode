/*
Given an array of positive integers nums, return the maximum possible sum of
an in nums.

A subarray is defined as a contiguous sequence of numbers in an array. */

#include <bits/stdc++.h>

class Solution {
public:
  [[nodiscard]] static int maxAscendingSum(const std::vector<int>& array) {
    int array_size = static_cast<int>(array.size());
    int max_subarray_sum = 0;
    if (array_size == 0) {
      return max_subarray_sum;
    }
    int curr_ind = 0;
    while (curr_ind < array_size) {
      int new_subarray_sum = array[curr_ind];
      while ((curr_ind + 1 < array_size) &&
             (array[curr_ind + 1] > array[curr_ind])) {
        ++curr_ind;
        new_subarray_sum += array[curr_ind];
      }
      if (new_subarray_sum > max_subarray_sum) {
        max_subarray_sum = new_subarray_sum;
      }
      ++curr_ind;
    }
    return max_subarray_sum;
  }
};