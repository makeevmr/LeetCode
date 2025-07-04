/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Time complexity: (k * log(k) * lists[i].length) because merge sort of k elements is k * log(k), and
leaf nodes lists have lists[i].length size
Additional memory complexity: O(log(k))
Idea: Divide & Conquer approach. Merge sort idea. Split array in two parts until only 2 lists
remains, merge all lists when climbing the recursion tree
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0),
          next(nullptr) {}
    explicit ListNode(int x)
        : val(x),
          next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x),
          next(next) {}
};

#include <vector>

class Solution {
public:
    static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int lists_size = static_cast<int>(lists.size());
        if (lists_size == 0) {
            return nullptr;
        }
        if (lists_size == 1) {
            return lists[0];
        }
        merge(lists, 0, lists_size - 1);
        return lists[0];
    }

private:
    static ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* new_root = nullptr;
        if (left != nullptr && right != nullptr) {
            ListNode* curr_left = left;
            ListNode* curr_right = right;
            if (curr_left->val <= curr_right->val) {
                new_root = curr_left;
                curr_left = curr_left->next;
            } else {
                new_root = curr_right;
                curr_right = curr_right->next;
            }
            ListNode* curr_merged = new_root;
            while (curr_left != nullptr && curr_right != nullptr) {
                if (curr_left->val <= curr_right->val) {
                    curr_merged->next = curr_left;
                    curr_left = curr_left->next;
                } else {
                    curr_merged->next = curr_right;
                    curr_right = curr_right->next;
                }
                curr_merged = curr_merged->next;
            }
            if (curr_left != nullptr) {
                curr_merged->next = curr_left;
            } else {
                curr_merged->next = curr_right;
            }
        } else if (left != nullptr) {
            new_root = left;
        } else if (right != nullptr) {
            new_root = right;
        }
        return new_root;
    }

    static void merge(std::vector<ListNode*>& lists, int left, int right) {
        int middle = (left + right) >> 1;
        if (right - left > 1) {
            merge(lists, left, middle);
            merge(lists, middle + 1, right);
        }
        if (left == right) {
            return;
        }
        lists[left] = mergeTwoLists(lists[left], lists[middle + 1]);
    }
};
