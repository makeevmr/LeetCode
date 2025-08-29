/* Given the root of a binary tree, return the level order traversal of its
nodes' values. (i.e., from left to right, level by level). Time complexity: O(n)
Additional memory complexity: O(n)
Idea: use breadth-first-search (BFS)
*/

#include <iostream>
#include <queue>
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
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> answer;
    if (root == nullptr) {
      return answer;
    }
    std::queue<TreeNode*> level_nodes;
    level_nodes.push(root);
    while (!level_nodes.empty()) {
      answer.push_back(std::vector<int>());
      std::size_t nodes_on_level = level_nodes.size();
      while (nodes_on_level > 0) {
        TreeNode* curr_node = level_nodes.front();
        answer.back().push_back(curr_node->val);
        if (curr_node->left != nullptr) {
          level_nodes.push(curr_node->left);
        }
        if (curr_node->right != nullptr) {
          level_nodes.push(curr_node->right);
        }
        level_nodes.pop();
        --nodes_on_level;
      }
    }
    return answer;
  }
};
