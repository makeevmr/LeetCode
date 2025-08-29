#include <iostream>
#include <vector>

class Solution {
public:
  static int candy(const std::vector<int>& ratings) {
    std::vector<int> candy_array;
    size_t ratings_size = ratings.size();
    for (size_t i = 0; i < ratings_size; ++i) {
      if (i == 0) {
        candy_array.push_back(1);
      } else {
        if (ratings[i - 1] < ratings[i]) {
          candy_array.push_back(candy_array.back() + 1);
        } else {
          candy_array.push_back(1);
        }
      }
    }
    int total_candy = 0;
    for (int i = static_cast<int>(ratings_size) - 2; i >= 0; --i) {
      total_candy += candy_array[i + 1];
      if ((ratings[i] > ratings[i + 1]) &&
          (candy_array[i] <= candy_array[i + 1])) {
        candy_array[i] = candy_array[i + 1] + 1;
      }
    }
    if (!ratings.empty()) {
      total_candy += candy_array[0];
    }
    return total_candy;
  }
};

int main() {
  std::vector<int> ratings = {1, 3, 4, 5, 2};
  std::cout << Solution::candy(ratings) << std::endl;
  return 0;
}
