/* Given the head of a linked list, rotate the list to the right by k places.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: calculate list size, cut list, last_node->next = head
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
    static ListNode *rotateRight(ListNode *head, int k) {
        std::size_t list_size = getListSize(head);
        if (list_size == 0) {
            return head;
        }
        std::size_t total_rotates = static_cast<std::size_t>(k) % list_size;
        if (total_rotates == 0) {
            return head;
        }
        std::size_t nodes_to_pass = list_size - total_rotates - 1;
        ListNode *curr_node = head;
        while (nodes_to_pass > 0) {
            curr_node = curr_node->next;
            --nodes_to_pass;
        }
        ListNode *new_head = curr_node->next;
        curr_node->next = nullptr;
        curr_node = new_head;
        while (curr_node->next != nullptr) {
            curr_node = curr_node->next;
        }
        curr_node->next = head;
        return new_head;
    }

private:
    static std::size_t getListSize(const ListNode *head) {
        std::size_t list_size = 0;
        const ListNode *curr_node = head;
        while (curr_node != nullptr) {
            ++list_size;
            curr_node = curr_node->next;
        }
        return list_size;
    }
};
