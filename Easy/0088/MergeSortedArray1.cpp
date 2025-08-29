#include <iostream>
#include <vector>

class Solution {
public:
  static void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2,
                    int n) {
    int nums1_index = m - 1;
    int nums2_index = n - 1;
    int united_array_index = n + m - 1;
    while (nums1_index >= 0 && nums2_index >= 0) {
      if (nums1[nums1_index] <= nums2[nums2_index]) {
        nums1[united_array_index] = nums2[nums2_index];
        --nums2_index;
      } else {
        nums1[united_array_index] = nums1[nums1_index];
        --nums1_index;
      }
      --united_array_index;
    }
    while (nums2_index >= 0) {
      nums1[united_array_index] = nums2[nums2_index];
      --nums2_index;
      --united_array_index;
    }
  }
};

int main() {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {2, 5, 6};
  Solution::merge(nums1, static_cast<int>(nums1.size() - nums2.size()), nums2,
                  static_cast<int>(nums2.size()));
  for (int i = 0; i < nums1.size(); ++i) {
    std::cout << nums1[i] << ' ';
  }
  return 0;
}
