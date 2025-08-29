/* Given the head of a singly linked list, reverse the list, and return the
reversed list. Time complexity: O(n) Additional memory complexity: O(1) Idea:
use three pointers (prev, curr, next)
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

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;
    head->next = nullptr;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
