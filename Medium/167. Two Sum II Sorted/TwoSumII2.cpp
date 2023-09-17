#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(const std::vector<int> &numbers, int target) {
        int left_index = -1;
        int right_index = 0;
        int numbers_size = static_cast<int>(numbers.size());
        int right_border = numbers_size - 1;
        int middle = 0;
        int number_to_find = 0;
        do {
            ++left_index;
            number_to_find = target - numbers[left_index];
            int left_border = left_index + 1;
            while (left_border < right_border) {
                middle = (left_border + right_border) / 2;
                if (numbers[middle] == number_to_find) {
                    break;
                } else if (number_to_find < numbers[middle]) {
                    right_border = middle - 1;
                } else {
                    left_border = middle + 1;
                }
            }
            right_index = (left_border + right_border) / 2;
        } while (numbers[right_index] != number_to_find);
        return std::vector<int>{left_index + 1, right_index + 1};
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 4, 9, 56, 90};
    int target = 8;
    std::vector<int> solution = Solution::twoSum(numbers, target);
    std::cout << solution[0] << ' ' << solution[1] << std::endl;
    return 0;
}
