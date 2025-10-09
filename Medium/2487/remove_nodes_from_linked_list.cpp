#include <utility>

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
  [[nodiscard]] static ListNode* removeNodes(ListNode* head) {
    return traverseList(head).first;
  }

private:
  [[nodiscard]] static std::pair<ListNode*, int> traverseList(
      ListNode* curr_node) {
    if (curr_node->next == nullptr) {
      return {curr_node, curr_node->val};
    }
    auto [right_head, max_value] = traverseList(curr_node->next);
    if (max_value > curr_node->val) {
      curr_node->next = nullptr;
    } else {
      curr_node->next = right_head;
      max_value = curr_node->val;
      right_head = curr_node;
    }
    return {right_head, max_value};
  }
};