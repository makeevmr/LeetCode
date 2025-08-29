/* Given the root of a binary tree and an integer targetSum, return true if the
tree has a root-to-leaf path such that adding up all the values along the path
equals targetSum. A leaf is a node with no children. Time complexity: O(n)
Additional memory complexity: O(height of BT)
Idea: use recursion
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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == 0;
    }
    bool has_left_sum =
        root->left == nullptr ? false : hasPathSum(root->left, targetSum);
    bool has_right_sum =
        root->right == nullptr ? false : hasPathSum(root->right, targetSum);
    return has_left_sum || has_right_sum;
  }
};