/* Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child
pointer points to the next node in the list and the left child pointer is always
null. The "linked list" should be in the same order as a pre-order traversal of
the binary tree. Time complexity: O(n) Additional memory complexity: O(height of
BT) Idea: return pair(head, tail) on each straightenTree() call
*/

#include <iostream>
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
  static void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    straightenTree(root);
  }

private:
  static std::pair<TreeNode*, TreeNode*> straightenTree(TreeNode* root) {
    TreeNode* head = root;
    TreeNode* tail = root;
    TreeNode* left_node = root->left;
    TreeNode* right_node = root->right;
    if (left_node) {
      std::pair<TreeNode*, TreeNode*> left_tree = straightenTree(left_node);
      head->left = nullptr;
      head->right = left_tree.first;
      tail = left_tree.second;
    }
    if (right_node) {
      std::pair<TreeNode*, TreeNode*> right_tree = straightenTree(right_node);
      tail->left = nullptr;
      tail->right = right_tree.first;
      tail = right_tree.second;
    }
    return std::pair<TreeNode*, TreeNode*>{head, tail};
  }
};
