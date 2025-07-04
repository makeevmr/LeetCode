/* Given two strings word1 and word2, return the minimum number of operations required to convert
word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
Time complexity: O(word1_size * word2_size)
Additional memory complexity: O(word2_size)
Idea: use dynamic programming approach (dp_matrix[i][j] contain min edit for word1[0..i),
word2[0..j))
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    [[nodiscard]] static int minDistance(const std::string& word1, const std::string& word2) {
        int word1_size = static_cast<int>(word1.size());
        int word2_size = static_cast<int>(word2.size());
        std::vector<int> dp_array(word2_size + 1, 0);
        for (int j = 1; j <= word2_size; ++j) {
            dp_array[j] = j;
        }
        for (int i = 1; i <= word1_size; ++i) {
            int prev_diag_val = dp_array[0];
            int new_diag_val = -1;
            ++dp_array[0];
            for (int j = 1; j <= word2_size; ++j) {
                new_diag_val = dp_array[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp_array[j] = prev_diag_val;
                } else {
                    dp_array[j] =
                        std::min(std::min(dp_array[j], dp_array[j - 1]), prev_diag_val) + 1;
                }
                prev_diag_val = new_diag_val;
            }
        }
        return dp_array.back();
    }
};