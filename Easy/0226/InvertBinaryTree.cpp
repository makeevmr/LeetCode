/* Given the root of a binary tree, invert the tree, and return its root.
Time complexity: O(n)
Additional memory complexity: O(max depth of BST)
Idea: use forward tree traversal
*/

#include <utility>

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
  static TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
  }
};
