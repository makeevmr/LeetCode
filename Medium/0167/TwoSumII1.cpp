#include <iostream>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int left_index = 0;
    int right_index = static_cast<int>(numbers.size()) - 1;
    std::vector<int> result;
    while (left_index < right_index) {
      if (numbers[left_index] + numbers[right_index] == target) {
        result.push_back(left_index + 1);
        result.push_back(right_index + 1);
        break;
      } else if (numbers[left_index] + numbers[right_index] > target) {
        --right_index;
      } else {
        ++left_index;
      }
    }
    return result;
  }
};

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 4, 9, 56, 90};
  int target = 8;
  std::vector<int> solution = Solution::twoSum(numbers, target);
  std::cout << solution[0] << ' ' << solution[1] << std::endl;
  return 0;
}
