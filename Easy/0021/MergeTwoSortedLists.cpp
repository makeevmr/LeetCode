/* You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists. Return the head of the merged linked
list. Time complexity: O(len(list1) + len(list2)) Additional memory complexity:
O(1) Idea: iterate through lists and choose min value on each iteration
*/

#include <algorithm>

//  Definition for singly-linked list.
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* merged_list = nullptr;
    ListNode* curr_node = nullptr;
    bool is_first_iter = true;
    while (list1 != nullptr || list2 != nullptr) {
      ListNode* new_node = nullptr;
      if (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
          new_node = new ListNode(list1->val);
          list1 = list1->next;
        } else {
          new_node = new ListNode(list2->val);
          list2 = list2->next;
        }
      } else {
        if (list1 != nullptr) {
          new_node = new ListNode(list1->val);
          list1 = list1->next;
        } else {
          new_node = new ListNode(list2->val);
          list2 = list2->next;
        }
      }
      if (is_first_iter) {
        merged_list = new_node;
        curr_node = new_node;
        is_first_iter = false;
      } else {
        curr_node->next = new_node;
        curr_node = new_node;
      }
    }
    return merged_list;
  }
};
