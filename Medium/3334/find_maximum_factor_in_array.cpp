#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>

class Solution {
public:
  std::int64_t maxScore(const std::vector<int>& nums) {
    const std::size_t nums_size = nums.size();
    if (nums_size == 1) {
      return nums[0] * nums[0];
    }
    std::vector<uint64_t> gcd_pref(nums_size, 0);
    std::vector<uint64_t> lcm_pref(nums_size, 0);
    gcd_pref[0] = nums[0];
    lcm_pref[0] = nums[0];
    for (std::size_t i = 1; i < nums_size; ++i) {
      gcd_pref[i] = gcd(gcd_pref[i - 1], nums[i]);
      lcm_pref[i] = lcm(lcm_pref[i - 1], nums[i]);
    }
    std::vector<uint64_t> gcd_suff(nums_size, 0);
    std::vector<uint64_t> lcm_suff(nums_size, 0);
    gcd_suff.back() = nums.back();
    lcm_suff.back() = nums.back();
    for (std::ptrdiff_t i = static_cast<std::ptrdiff_t>(nums_size - 2); i >= 0;
         --i) {
      gcd_suff[i] = gcd(gcd_suff[i + 1], nums[i]);
      lcm_suff[i] = lcm(lcm_suff[i + 1], nums[i]);
    }
    std::uint64_t answer = gcd_pref.back() * lcm_pref.back();
    for (std::size_t i = 0; i < nums_size; ++i) {
      std::uint64_t new_answer = 0;
      if (i == 0) {
        new_answer = gcd_suff[i + 1] * lcm_suff[i + 1];
      } else if (i == nums_size - 1) {
        new_answer = gcd_pref[i - 1] * lcm_pref[i - 1];
      } else {
        new_answer = gcd(gcd_pref[i - 1], gcd_suff[i + 1]) *
                     lcm(lcm_pref[i - 1], lcm_suff[i + 1]);
      }
      answer = std::max(answer, new_answer);
    }
    return static_cast<std::int64_t>(answer);
  }

private:
  std::uint64_t gcd(std::uint64_t a, std::uint64_t b) {
    while (b != 0) {
      a %= b;
      std::swap(a, b);
    }
    return a;
  }

  std::uint64_t lcm(std::uint64_t a, std::uint64_t b) {
    return (a * b) / gcd(a, b);
  }
};