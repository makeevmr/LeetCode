/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are
divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3
+ s3 + ... Note: a + b is the concatenation of strings a and b. Time complexity:
(s1_size * s2_size) Additional memory complexity: O(s2_size) Idea: use dynamic
programming approach (dp_matrix[i][j] equals true if we can construct s3[0...(i
+ j + 1)] with i + 1 first symbols from s1 and j + 1 first symbols from s2) use
dp_array instead dp_matrix because no need to use O(s1_size * s2_size)
additional memory
*/

#include <string>
#include <vector>

class Solution {
public:
  [[nodiscard]] static bool isInterleave(const std::string& s1,
                                         const std::string& s2,
                                         const std::string& s3) {
    int s1_size = static_cast<int>(s1.size());
    int s2_size = static_cast<int>(s2.size());
    int s3_size = static_cast<int>(s3.size());
    if (s1_size + s2_size != s3_size) {
      return false;
    }
    std::vector<bool> dp_array;
    dp_array.reserve(s2_size + 1);
    dp_array.push_back(true);
    for (int s2_ind = 0; s2_ind < s2_size; ++s2_ind) {
      dp_array.push_back(dp_array[s2_ind] && (s2[s2_ind] == s3[s2_ind]));
    }
    for (int s1_ind = 0; s1_ind < s1_size; ++s1_ind) {
      dp_array[0] = dp_array[0] && (s1[s1_ind] == s3[s1_ind]);
      for (int s2_ind = 0; s2_ind < s2_size; ++s2_ind) {
        dp_array[s2_ind + 1] =
            (dp_array[s2_ind] && s3[s1_ind + s2_ind + 1] == s2[s2_ind]) ||
            (dp_array[s2_ind + 1] && s3[s1_ind + s2_ind + 1] == s1[s1_ind]);
      }
    }
    return dp_array.back();
  }
};