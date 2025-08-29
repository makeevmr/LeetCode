/* Given the root of a binary tree, check whether it is a mirror of itself
(i.e., symmetric around its center). Time complexity: O(n) Additional memory
complexity: O(depth of BST) Idea: use forward tree traversal
*/

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
  static bool isSymmetric(TreeNode* root) {
    return isSymmetricSubtrees(root->left, root->right);
  }

private:
  static bool isSymmetricSubtrees(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if ((left == nullptr) || (right == nullptr) || (left->val != right->val)) {
      return false;
    }
    return isSymmetricSubtrees(left->left, right->right) &&
           isSymmetricSubtrees(left->right, right->left);
  }
};
