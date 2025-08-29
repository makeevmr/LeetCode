/* Given the root of a binary tree, determine if it is a valid binary search
tree (BST). A valid BST is defined as follows: The left subtree of a node
contains only nodes with keys less than the node's key. The right subtree of a
node contains only nodes with keys greater than the node's key. Both the left
and right subtrees must also be binary search trees. Time complexity: O(n),
where n is total number of nodes Additional memory complexity: O(height of tree)
Idea: use std::pair to determine the boundary of possible values for each
subtree
*/

#include <limits>
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
  [[nodiscard]] static bool isValidBST(TreeNode* root) {
    return isValidSubtree(root, {std::numeric_limits<long long int>::min(),
                                 std::numeric_limits<long long int>::max()});
  }

private:
  [[nodiscard]] static bool isValidSubtree(
      TreeNode* root, std::pair<long long int, long long int> border) {
    if (root == nullptr) {
      return true;
    }
    if (border.first >= root->val || root->val >= border.second) {
      return false;
    }
    return isValidSubtree(root->left, {border.first, root->val}) &&
           isValidSubtree(root->right, {root->val, border.second});
  }
};
