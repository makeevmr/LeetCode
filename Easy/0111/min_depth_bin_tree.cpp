#include <cmath>

// Definition for a binary tree node.
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

class Solution {
public:
  [[nodiscard]] static int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return getSubtreeDepth(root);
  }

private:
  [[nodiscard]] static int getSubtreeDepth(TreeNode* root) {
    if (root->left != nullptr && root->right != nullptr) {
      return 1 + std::min(getSubtreeDepth(root->left),
                          getSubtreeDepth(root->right));
    } else if (root->left != nullptr) {
      return 1 + getSubtreeDepth(root->left);
    } else if (root->right != nullptr) {
      return 1 + getSubtreeDepth(root->right);
    }
    return 1;
  }
};