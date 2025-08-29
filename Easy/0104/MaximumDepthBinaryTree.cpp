/* Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node. Time complexity: O(n) Additional
memory complexity: O(max depth of BST) Idea: use forward tree traversal
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
  static int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int left_subtree_depth = maxDepth(root->left);
    int right_subtree_depth = maxDepth(root->right);
    return (left_subtree_depth > right_subtree_depth ? left_subtree_depth
                                                     : right_subtree_depth) +
           1;
  }
};
