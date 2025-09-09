#include <vector>
#include <string>
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
    std::sort(str_nums.begin(), str_nums.end(),
              [](const std::string& left, const std::string& right) {
                return (left + right) > (right + left);
              });
    std::string ans;
    ans.reserve(total_str_size);
    for (const auto& str_num : str_nums) {
      ans.append(str_num);
    }
    return ans[0] == '0' ? "0" : ans;
  }
};
