/* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving
only distinct numbers from the original list. Return the linked list sorted as well.
Time complexity: O(n), where n is size of linked list
Additional memory complexity: O(1)
Idea: iterate through linked list, delete node if list already contains value
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr_node = head;
        ListNode *no_duplicates_head = nullptr;
        ListNode *no_duplicates_curr_node = nullptr;
        while (curr_node != nullptr) {
            ListNode *node_to_add = curr_node;
            bool is_unique = true;
            curr_node = curr_node->next;
            while (curr_node != nullptr && curr_node->val == node_to_add->val) {
                is_unique = false;
                curr_node = curr_node->next;
            }
            if (is_unique) {
                if (no_duplicates_head == nullptr) {
                    no_duplicates_head = node_to_add;
                    no_duplicates_curr_node = no_duplicates_head;
                } else {
                    no_duplicates_curr_node->next = node_to_add;
                    no_duplicates_curr_node = no_duplicates_curr_node->next;
                }
                no_duplicates_curr_node->next = nullptr;
            }
        }
        return no_duplicates_head;
    }
};
