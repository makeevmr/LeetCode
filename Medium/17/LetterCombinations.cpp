/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does
not map to any letters.
Time complexity: O(4 ^ (digits_size) * digits_size)
Additional memory complexity: O(digits_size)
Idea: use recursion to find all possible combinations of letters
*/

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<std::string> letterCombinations(const std::string& digits) {
        std::vector<std::string> combinations_array;
        if (digits.size() == 0) {
            return combinations_array;
        }
        std::string curr_combination(digits.size(), '#');
        getAllCombinations(digits, combinations_array, curr_combination, 0);
        return combinations_array;
    }

private:
    static void getAllCombinations(const std::string& digits,
                                   std::vector<std::string>& combinations_array,
                                   std::string& curr_combination, int level) {
        if (level == static_cast<int>(digits.size())) {
            combinations_array.push_back(curr_combination);
            return;
        }
        for (const auto& letter : letters_map.find(digits[level] - '0')->second) {
            curr_combination[level] = letter;
            getAllCombinations(digits, combinations_array, curr_combination, level + 1);
        }
    }

    static const std::unordered_map<int, std::string> letters_map;
};

const std::unordered_map<int, std::string> Solution::letters_map = {
    {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
    {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
