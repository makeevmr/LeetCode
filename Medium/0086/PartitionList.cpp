/* Given the head of a linked list and a value x, partition it such that all
nodes less than x come before nodes greater than or equal to x. You should
preserve the original relative order of the nodes in each of the two partitions.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: create two lists less_x and not_less_x, add new node to one of them
depending on the value x
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
  static ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) {
      return head;
    }
    ListNode* less_x_head = nullptr;
    ListNode* less_x_curr_node = nullptr;
    ListNode* not_less_x_head = nullptr;
    ListNode* not_less_x_curr_node = nullptr;
    ListNode* curr_node = head;
    while (curr_node != nullptr) {
      if (curr_node->val < x) {
        addNode(less_x_head, less_x_curr_node, curr_node);
      } else {
        addNode(not_less_x_head, not_less_x_curr_node, curr_node);
      }
      curr_node = curr_node->next;
    }
    if (less_x_curr_node != nullptr) {
      less_x_curr_node->next = not_less_x_head;
    }
    if (not_less_x_curr_node != nullptr) {
      not_less_x_curr_node->next = nullptr;
    }
    head = less_x_head != nullptr ? less_x_head : not_less_x_head;
    return head;
  }

private:
  static void addNode(ListNode*& head, ListNode*& curr_node,
                      ListNode* const& node_to_add) {
    if (head == nullptr) {
      head = node_to_add;
    } else {
      curr_node->next = node_to_add;
    }
    curr_node = node_to_add;
  }
};
