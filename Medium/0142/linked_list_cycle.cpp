struct ListNode {
  int val;
  ListNode* next;

  explicit ListNode(int x)
      : val(x),
        next(nullptr) {}
};

class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* slow_ptr = head;
    ListNode* fast_ptr = head;
    do {
      slow_ptr = slow_ptr->next;
      for (int i = 0; i < 2; ++i) {
        fast_ptr = fast_ptr->next;
        if (fast_ptr == nullptr) {
          return nullptr;
        }
      }
    } while (slow_ptr != fast_ptr);
    ListNode* curr_node = head;
    while (curr_node != slow_ptr) {
      curr_node = curr_node->next;
      slow_ptr = slow_ptr->next;
    }
    return curr_node;
  }
};