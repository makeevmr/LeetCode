/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
Time complexity: O(n * log(n))
Additional memory complexity: O(n)
Idea: use std::priority_queue
*/

#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> max_heap{nums.begin(), nums.end()};
        int curr_max_num = 1;
        while (curr_max_num != k) {
            max_heap.pop();
            ++curr_max_num;
        }
        return max_heap.top();
    }
};