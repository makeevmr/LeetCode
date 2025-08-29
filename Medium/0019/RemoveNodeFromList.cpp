/* Given the head of a linked list, remove the nth node from the end of the list
and return its head. Time complexity: O(length of list) Additional memory
complexity: O(1) Idea: calculate list size than remove node
*/

#include <iostream>

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int list_size = getListSize(head);
    int nodes_to_pass = list_size - n;
    ListNode* parent_of_deleted = nullptr;
    while (nodes_to_pass > 0) {
      if (parent_of_deleted == nullptr) {
        parent_of_deleted = head;
      } else {
        parent_of_deleted = parent_of_deleted->next;
      }
      --nodes_to_pass;
    }
    if (parent_of_deleted == nullptr) {
      head = head->next;
    } else {
      if (n == 1) {
        parent_of_deleted->next = nullptr;
      } else {
        parent_of_deleted->next = parent_of_deleted->next->next;
      }
    }
    return head;
  }

private:
  int getListSize(ListNode* head) {
    int list_size = 0;
    ListNode* curr_node = head;
    while (curr_node != nullptr) {
      ++list_size;
      curr_node = curr_node->next;
    }
    return list_size;
  }
};

int main() {
  return 0;
}