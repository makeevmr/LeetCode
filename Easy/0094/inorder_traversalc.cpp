// Given the root of a binary tree, return the inorder traversal of its nodes'
// values.

#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
      : val(0),
        left(nullptr),
        right(nullptr) {}
  explicit TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x),
        left(left),
        right(right) {}
};

#include <vector>

class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    std::vector<int> traversal_res;
    std::stack<TreeNode*> stack_path;
    TreeNode* curr_node = root;
    while (curr_node->left != nullptr) {
      stack_path.push(curr_node);
      curr_node = curr_node->left;
    }
    traversal_res.push_back(curr_node->val);
    while (curr_node != nullptr) {
      curr_node = getNextNode(curr_node, stack_path);
      if (curr_node != nullptr) {
        traversal_res.push_back(curr_node->val);
      }
    }
    return traversal_res;
  }

private:
  [[nodiscard]] TreeNode* getNextNode(TreeNode* curr_node,
                                      std::stack<TreeNode*>& stack_path) {
    if (curr_node->right != nullptr) {
      stack_path.push(curr_node);
      curr_node = curr_node->right;
      while (curr_node->left != nullptr) {
        stack_path.push(curr_node);
        curr_node = curr_node->left;
      }
      return curr_node;
    }
    while (!stack_path.empty() && stack_path.top()->right == curr_node) {
      curr_node = stack_path.top();
      stack_path.pop();
    }
    if (stack_path.empty()) {
      return nullptr;
    }
    curr_node = stack_path.top();
    stack_path.pop();
    return curr_node;
  }
};
