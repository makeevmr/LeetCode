/*Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by
continuously following the next pointer. Internally, pos is used to denote the index of the node
that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Time complexity: O(n), where n is number of nodes in list
Additional memory complexiy: O(1)
Idea: use Floyd's Tortoise and Hare Algorithm
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;
        while (slow_ptr->next != nullptr) {
            slow_ptr = slow_ptr->next;
            if (fast_ptr->next == nullptr) {
                return false;
            }
            fast_ptr = fast_ptr->next;
            if (fast_ptr->next == nullptr) {
                return false;
            }
            fast_ptr = fast_ptr->next;
            if (slow_ptr == fast_ptr) {
                return true;
            }
        }
        return false;
    }
};

int main() { return 0; }
