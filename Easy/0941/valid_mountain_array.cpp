#include <vector>

class Solution {
public:
  [[nodiscard]] static bool validMountainArray(const std::vector<int>& arr) {
    const std::size_t arr_size = arr.size();
    if (arr_size < 3ULL) {
      return false;
    }
    std::size_t i = 0;
    while ((i + 1) < arr_size && arr[i] < arr[i + 1]) {
      ++i;
    }
    while ((i + 1) < arr_size && arr[i] > arr[i + 1]) {
      ++i;
    }
    return (i == arr_size - 1 && (arr[i - 1] > arr[i]) && (arr[0] < arr[1]));
  }
};