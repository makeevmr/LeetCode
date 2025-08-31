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
  [[nodiscard]] static ListNode* swapPairs(ListNode* head) {
    int visited = 0;
    ListNode* prev_pair = nullptr;
    ListNode* prev_node = nullptr;
    ListNode* new_root = head;
    ListNode* curr_node = head;
    while (curr_node != nullptr) {
      ++visited;
      if (visited == 2) {
        prev_node->next = curr_node->next;
        curr_node->next = prev_node;
        if (prev_pair != nullptr) {
          prev_pair->next = curr_node;
        } else {
          new_root = curr_node;
        }
        prev_pair = prev_node;
        curr_node = prev_node;
        visited = 0;
      }
      prev_node = curr_node;
      curr_node = curr_node->next;
    }
    return new_root;
  }
};