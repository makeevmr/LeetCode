#include <unordered_set>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x)
      : val(x),
        next(nullptr) {}
};

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b) {
    ListNode* curr_a = head_a;
    std::unordered_set<ListNode*> nodes_met;
    while (curr_a != nullptr) {
      nodes_met.insert(curr_a);
      curr_a = curr_a->next;
    }
    ListNode* curr_b = head_b;
    while (curr_b != nullptr) {
      if (nodes_met.contains(curr_b)) {
        return curr_b;
      }
      curr_b = curr_b->next;
    }
    return nullptr;
  }
};
