/*
Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list. Time complexity: O(n) Additional memory
complexity: O(1) Idea: reverse part of linked list
*/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode()
      : val(0),
        next(nullptr) {}
  ListNode(int x)
      : val(x),
        next(nullptr) {}
  ListNode(int x, ListNode* next)
      : val(x),
        next(next) {}
};

class Solution {
public:
  static ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode* reverse_head = nullptr;
    ListNode* reverse_tail = nullptr;
    ListNode* before_reversed = nullptr;
    ListNode* after_reversed = nullptr;
    ListNode* curr_node = head;
    int curr_node_index = 1;
    while (curr_node_index < (left - 1)) {
      curr_node = curr_node->next;
      ++curr_node_index;
    }
    if (curr_node_index == left - 1) {
      before_reversed = curr_node;
      reverse_head = before_reversed->next;
      curr_node = reverse_head->next;
      curr_node_index += 2;
    } else {
      before_reversed = nullptr;
      reverse_head = curr_node;
      curr_node = reverse_head->next;
      ++curr_node_index;
    }
    ListNode* prev_node = reverse_head;
    while (curr_node_index <= right) {
      ListNode* next_node = curr_node->next;
      curr_node->next = prev_node;
      if (curr_node_index == right) {
        after_reversed = next_node;
        reverse_tail = curr_node;
      }
      prev_node = curr_node;
      curr_node = next_node;
      ++curr_node_index;
    }
    if (before_reversed != nullptr) {
      before_reversed->next = reverse_tail;
    }
    reverse_head->next = after_reversed;
    return left == 1 ? reverse_head : head;
  }
};

int main() {
  ListNode* head = new ListNode(3);
  ListNode* next = new ListNode(5);
  head->next = next;
  Solution::reverseBetween(head, 1, 2);
  return 0;
}
