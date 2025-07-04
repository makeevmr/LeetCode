/* Given an unsorted array of integers nums, return the length of the longest consecutive elements
sequence.
You must write an algorithm that runs in O(n) time.
Time complexity: O(n)
Additional memory complexity: O(n)
Idea: use 2 unordered_maps.
First contains start number of sequence as key and length of sequence as value
Second contains end number of sequence as key and length of sequence as value
Iterate through nums and fill unordered_maps, then while unordered_maps is not empty concatinate
sequences
*/

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    static int longestConsecutive(const std::vector<int> &nums) {
        std::unordered_map<int, int> seq_start;
        std::unordered_map<int, int> seq_end;
        for (const auto &num : nums) {
            seq_start[num] = 1;
            seq_end[num] = 1;
        }
        int max_seq_len = 0;
        while (!seq_start.empty()) {
            auto b_iter = seq_start.begin();
            while (seq_start.contains(b_iter->first + b_iter->second)) {
                auto f_iter_start = seq_start.find(b_iter->first + b_iter->second);
                seq_end[f_iter_start->first + f_iter_start->second - 1] += b_iter->second;
                b_iter->second += f_iter_start->second;
                seq_end.erase(f_iter_start->first - 1);
                seq_start.erase(f_iter_start);
            }
            auto f_iter_end = seq_end.find(b_iter->first - 1);
            if (f_iter_end != seq_end.end()) {
                seq_start[f_iter_end->first - f_iter_end->second + 1] += b_iter->second;
                seq_end[b_iter->first + b_iter->second - 1] += f_iter_end->second;
                seq_start.erase(f_iter_end->first + 1);
                seq_end.erase(f_iter_end);
            } else {
                if (max_seq_len < b_iter->second) {
                    max_seq_len = b_iter->second;
                }
                seq_end.erase(b_iter->first + b_iter->second - 1);
                seq_start.erase(b_iter);
            }
        }
        return max_seq_len;
    }
};

int main() {
    // std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << Solution::longestConsecutive(nums) << '\n';
    return 0;
}
