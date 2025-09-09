#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::string largestNumber(const std::vector<int>& nums) {
    std::size_t nums_size = nums.size();
    std::vector<std::string> str_nums;
    str_nums.reserve(nums_size);
    size_t total_str_size = 0;
    for (const int& num : nums) {
      const std::string&& str_num = std::to_string(num);
      total_str_size += str_num.size();
      str_nums.push_back(str_num);
    }
    std::sort(str_nums.begin(), str_nums.end(), StrGreaterCompare());
    std::string ans;
    ans.reserve(total_str_size);
    for (const auto& str_num : str_nums) {
      ans.append(str_num);
    }
    if (ans[0] == '0') {
      ans = "0";
    }
    return ans;
  }

private:
  class StrGreaterCompare {
  public:
    bool operator()(const std::string& left,
                    const std::string& right) const noexcept {
      return isGreater(left, right, 0ULL, 0ULL, left.size(), right.size());
    }

  private:
    [[nodiscard]] static bool isGreater(
        const std::string& left, const std::string& right, std::size_t left_ind,
        std::size_t right_ind, const std::size_t& left_size,
        const std::size_t& right_size) noexcept {
      const size_t left_start = left_ind;
      const size_t right_start = right_ind;
      while (left_ind < left_size && right_ind < right_size) {
        if (left[left_ind] == right[right_ind]) {
          ++left_ind;
          ++right_ind;
          continue;
        }
        return left[left_ind] > right[right_ind];
      }
      if (left_ind == left_size && right_ind == right_size) {
        return false;
      }
      if (left_ind == left_size) {
        return isGreater(left, right, left_start, right_ind, left_size,
                         right_size);
      }
      return isGreater(left, right, left_ind, right_start, left_size,
                       right_size);
    }
  };
};