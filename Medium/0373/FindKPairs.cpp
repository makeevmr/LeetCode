/* You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the
second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
Time complexity: O(k * log(k))
Additional memory complexity: O(nums1_size + k)
Idea: let's consider current min pairs with fixed nums1_ind. It's pairs indexes are: (0, 0), (1, 0),
(2, 0) ... (nums1_size - 1, 0)
We contain sums of these pairs in min_heap, pop min_pair (i, j) and push sum that correspond to
pair(i, j + 1) into heap
*/

#include <queue>
#include <vector>

class Solution {
public:
    [[nodiscard]] static std::vector<std::vector<int>> kSmallestPairs(const std::vector<int>& nums1,
                                                                      const std::vector<int>& nums2,
                                                                      int k) {
        std::vector<std::vector<int>> answer;
        int nums1_ind = 0;
        int nums1_size = static_cast<int>(nums1.size());
        int nums2_size = static_cast<int>(nums2.size());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            LessPairComparator<int>>
            pairs_sum_min_heap;
        std::vector<int> curr_pairs(nums1_size, 0);
        while (nums1_ind < nums1_size && nums1_ind < k) {
            pairs_sum_min_heap.push(std::pair<int, int>{nums1[nums1_ind] + nums2[0], nums1_ind});
            ++nums1_ind;
        }
        while (k > 0) {
            const std::pair<int, int>& top_pair = pairs_sum_min_heap.top();
            answer.push_back({nums1[top_pair.second], nums2[curr_pairs[top_pair.second]]});
            if (curr_pairs[top_pair.second] + 1 < nums2_size) {
                ++curr_pairs[top_pair.second];
                pairs_sum_min_heap.push(std::pair<int, int>{
                    nums1[top_pair.second] + nums2[curr_pairs[top_pair.second]], top_pair.second});
            }
            pairs_sum_min_heap.pop();
            --k;
        }
        return answer;
    }

private:
    template <typename T>
    class LessPairComparator {
    public:
        bool operator()(const std::pair<T, T>& left, const std::pair<T, T>& right) {
            return left.first > right.first;
        }
    };
};