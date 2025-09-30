#include <vector>
#include <queue>

// Definition for a Node.
class Node {
public:
  int val_;
  std::vector<Node*> children_;

  Node() {}

  explicit Node(const int val) {
    val_ = val;
  }

  Node(const int val, const std::vector<Node*>& children) {
    val_ = val;
    children_ = children;
  }
};

class Solution {
public:
  [[nodiscard]] static std::vector<std::vector<int>> levelOrder(
      Node* const root) {
    if (root == nullptr) {
      return {};
    }
    std::queue<Node*> nodes_queue;
    nodes_queue.push(root);
    std::vector<std::vector<int>> answer = {{root->val_}};
    while (!nodes_queue.empty()) {
      const std::size_t curr_level_size = nodes_queue.size();
      std::vector<int> new_level_values;
      for (std::size_t i = 0; i < curr_level_size; ++i) {
        Node* curr_level_node = nodes_queue.front();
        for (Node* const new_level_node : curr_level_node->children_) {
          new_level_values.push_back(new_level_node->val_);
          nodes_queue.push(new_level_node);
        }
        nodes_queue.pop();
      }
      if (!new_level_values.empty()) {
        answer.push_back(std::move(new_level_values));
      }
    }
    return answer;
  }
};