/* Given an integer array nums, find a subarray that has the largest product,
and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer. */

#include <vector>
#include <limits>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int maxProduct(const std::vector<int>& nums) {
    int max_product = std::numeric_limits<int>::min();
    int max_negative_prefix_ind = -1;
    int max_negative_prefix_value = -1;
    int curr_prefix = 1;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      curr_prefix *= nums[i];
      if (curr_prefix > 0) {
        max_product = std::max(max_product, curr_prefix);
      } else if (curr_prefix == 0) {
        max_product = std::max(max_product, nums[i]);
        max_negative_prefix_ind = -1;
        max_negative_prefix_value = -1;
        curr_prefix = 1;
      } else {
        int new_product = -1;
        if (max_negative_prefix_ind != -1) {
          new_product = curr_prefix / max_negative_prefix_value;
        } else {
          new_product = nums[i];
          max_negative_prefix_ind = i;
          max_negative_prefix_value = curr_prefix;
        }
        max_product = std::max(max_product, new_product);
      }
    }
    return max_product;
  }
};
