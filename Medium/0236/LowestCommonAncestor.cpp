/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
in the tree. According to the definition of LCA on Wikipedia: “The lowest common
ancestor is defined between two nodes p and q as the lowest node in T that has
both p and q as descendants (where we allow a node to be a descendant of
itself). Time complexity: O(n) Additional memory complexity: O(height of BT)
Idea: use recursion
*/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode* left_res = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_res = lowestCommonAncestor(root->right, p, q);
    if (left_res == nullptr && right_res == nullptr) {
      return (root == p || root == q) ? root : nullptr;
    }
    if (left_res != nullptr && right_res != nullptr) {
      return root;
    }
    if (left_res != nullptr) {
      return (root == p || root == q) ? root : left_res;
    }
    return (root == p || root == q) ? root : right_res;
  }
};
