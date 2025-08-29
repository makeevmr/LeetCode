/* Given the head of a linked list, return the list after sorting it in
 * ascending order. */

#include <iostream>
#include <utility>
#include <limits>

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
  static ListNode* sortList(ListNode* head) {
    ListNode* second_list = nullptr;
    ListNode* new_head = head;
    do {
      std::pair<ListNode*, ListNode*> list_pair = splitLists(new_head);
      second_list = list_pair.second;
      new_head = list_pair.first;
      if (list_pair.second != nullptr) {
        new_head = mergeLists(list_pair.first, list_pair.second);
      }
    } while (second_list != nullptr);
    return new_head;
  }

private:
  static std::pair<ListNode*, ListNode*> splitLists(ListNode* full_head) {
    ListNode* split1_head = nullptr;
    ListNode* split2_head = nullptr;
    ListNode* split1_curr_node = nullptr;
    ListNode* split2_curr_node = nullptr;
    int prev_value = std::numeric_limits<int>::min();
    while (full_head != nullptr) {
      while (full_head != nullptr && full_head->val >= prev_value) {
        if (split1_curr_node == nullptr) {
          split1_head = full_head;
        } else {
          split1_curr_node->next = full_head;
        }
        split1_curr_node = full_head;
        prev_value = full_head->val;
        full_head = full_head->next;
      }
      prev_value = std::numeric_limits<int>::min();
      while (full_head != nullptr && full_head->val >= prev_value) {
        if (split2_curr_node == nullptr) {
          split2_head = full_head;
        } else {
          split2_curr_node->next = full_head;
        }
        split2_curr_node = full_head;
        prev_value = full_head->val;
        full_head = full_head->next;
      }
      prev_value = std::numeric_limits<int>::min();
    }
    if (split1_curr_node != nullptr) {
      split1_curr_node->next = nullptr;
    }
    if (split2_curr_node != nullptr) {
      split2_curr_node->next = nullptr;
    }
    return std::pair<ListNode*, ListNode*>{split1_head, split2_head};
  }

  static ListNode* mergeLists(ListNode* left, ListNode* right) {
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    ListNode* new_list_head = nullptr;
    int prev_left = std::numeric_limits<int>::min();
    int prev_right = std::numeric_limits<int>::min();
    if (left->val <= right->val) {
      new_list_head = left;
      prev_left = left->val;
      left = left->next;
    } else {
      new_list_head = right;
      prev_right = right->val;
      right = right->next;
    }
    ListNode* new_list_node = new_list_head;
    while (left != nullptr || right != nullptr) {
      while (left != nullptr && prev_left <= left->val && right != nullptr &&
             prev_right <= right->val) {
        if (left->val <= right->val) {
          new_list_node->next = left;
          new_list_node = left;
          prev_left = left->val;
          left = left->next;
        } else {
          new_list_node->next = right;
          new_list_node = right;
          prev_right = right->val;
          right = right->next;
        }
      }
      while (left != nullptr && prev_left <= left->val) {
        new_list_node->next = left;
        new_list_node = left;
        prev_left = left->val;
        left = left->next;
      }
      while (right != nullptr && prev_right <= right->val) {
        new_list_node->next = right;
        new_list_node = right;
        prev_right = right->val;
        right = right->next;
      }
      prev_left = std::numeric_limits<int>::min();
      prev_right = std::numeric_limits<int>::min();
    }
    return new_list_head;
  }
};

int main() {
  ListNode* fourth = new ListNode(3);
  ListNode* third = new ListNode(1, fourth);
  ListNode* second = new ListNode(2, third);
  ListNode* first = new ListNode(4, second);
  ListNode* new_head = Solution::sortList(first);
  while (new_head != nullptr) {
    std::cout << new_head->val << ' ';
    new_head = new_head->next;
  }
  std::cout << '\n';
  delete fourth;
  delete third;
  delete second;
  delete first;
  return 0;
}
