/* Given the head of a linked list, reverse the nodes of the list k at a time, and return the
modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of
nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: compute does curr_head form group if it does, than reverse it
*/

#include <utility>

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
    static ListNode *reverseKGroup(ListNode *head, int k) noexcept {
        if (k == 1) {
            return head;
        }
        ListNode *curr_head = head;
        ListNode *group_parent = nullptr;
        while (isFromGroup(curr_head, k)) {
            std::pair<ListNode *, ListNode *> new_group_head =
                reverseGroup(curr_head, group_parent, head, k);
            curr_head = new_group_head.first;
            group_parent = new_group_head.second;
        }
        return head;
    }

private:
    static bool isFromGroup(ListNode *head, const int k) noexcept {
        int counter = 0;
        while (head != nullptr && counter < k) {
            ++counter;
            head = head->next;
        }
        return counter == k;
    }

    static std::pair<ListNode *, ListNode *> reverseGroup(ListNode *group_head,
                                                          ListNode *group_parent, ListNode *&head,
                                                          const int k) noexcept {
        int reversed_nodes = 1;
        ListNode *prev_node = group_head;
        ListNode *curr_node = prev_node->next;
        ListNode *group_tail = nullptr;
        ListNode *group_descendant = nullptr;
        while (reversed_nodes < k) {
            ListNode *next_node = curr_node->next;
            curr_node->next = prev_node;
            if (reversed_nodes == k) {
                group_tail = curr_node;
                group_descendant = next_node;
            }
            prev_node = curr_node;
            curr_node = next_node;
            ++reversed_nodes;
        }
        if (group_parent == nullptr) {
            head = group_tail;
        } else {
            group_parent->next = group_tail;
        }
        group_head->next = group_descendant;
        return std::pair<ListNode *, ListNode *>{group_descendant, group_head};
    }
};
