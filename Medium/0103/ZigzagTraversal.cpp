/* Given the root of a binary tree, return the zigzag level order traversal of
its nodes' values. (i.e., from left to right, then right to left for the next
level and alternate between). Time complexity: O(n), where n is number of nodes
Additional memory complexity: O(n)
Idea: use BFS
*/

#include <stack>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
      : val(0),
        left(nullptr),
        right(nullptr) {}
  TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x),
        left(left),
        right(right) {}
};

class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> answer;
    if (root == nullptr) {
      return answer;
    }
    std::stack<TreeNode*> level_nodes;
    level_nodes.push(root);
    bool is_left_right_push = true;
    while (!level_nodes.empty()) {
      answer.push_back(std::vector<int>());
      std::size_t nodes_on_level = level_nodes.size();
      std::stack<TreeNode*> next_level;
      while (nodes_on_level > 0) {
        TreeNode* curr_node = level_nodes.top();
        answer.back().push_back(curr_node->val);
        if (is_left_right_push) {
          if (curr_node->left != nullptr) {
            next_level.push(curr_node->left);
          }
          if (curr_node->right != nullptr) {
            next_level.push(curr_node->right);
          }
        } else {
          if (curr_node->right != nullptr) {
            next_level.push(curr_node->right);
          }
          if (curr_node->left != nullptr) {
            next_level.push(curr_node->left);
          }
        }
        --nodes_on_level;
        level_nodes.pop();
      }
      is_left_right_push = !is_left_right_push;
      level_nodes = std::move(next_level);
    }
    return answer;
  }
};
