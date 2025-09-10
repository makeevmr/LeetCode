#include <vector>

class Solution {
public:
  [[nodiscard]] static int findDuplicate(const std::vector<int>& nums) {
    std::size_t slow = 0;
    std::size_t fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};