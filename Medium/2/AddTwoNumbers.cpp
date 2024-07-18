/* You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and
return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Time complexity: O(len(l1) + len(l2))
Additional memory complexity: O(1)
Idea: use column addition
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode((l1->val + l2->val) % 10);
        int overflow_add = (l1->val + l2->val) / 10;
        ListNode *curr_node = res;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *new_node = new ListNode((l1->val + l2->val + overflow_add) % 10);
            overflow_add = (l1->val + l2->val + overflow_add) / 10;
            l1 = l1->next;
            l2 = l2->next;
            curr_node->next = new_node;
            curr_node = new_node;
        }
        while (l1 != nullptr) {
            ListNode *new_node = new ListNode((l1->val + overflow_add) % 10);
            overflow_add = (l1->val + overflow_add) / 10;
            l1 = l1->next;
            curr_node->next = new_node;
            curr_node = new_node;
        }
        while (l2 != nullptr) {
            ListNode *new_node = new ListNode((l2->val + overflow_add) % 10);
            overflow_add = (l2->val + overflow_add) / 10;
            l2 = l2->next;
            curr_node->next = new_node;
            curr_node = new_node;
        }
        if (overflow_add > 0) {
            curr_node->next = new ListNode(overflow_add);
        }
        return res;
    }
};
