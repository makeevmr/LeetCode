/* Given two integer arrays inorder and postorder where inorder is the inorder
traversal of a binary tree and postorder is the postorder traversal of the same
tree, construct and return the binary tree. Time complexity: O(n) Additional
memory complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
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
  static TreeNode* buildTree(std::vector<int>& inorder,
                             std::vector<int>& postorder) {
    std::unordered_map<int, int> postorder_ind_m;
    int postorder_size = static_cast<int>(postorder.size());
    for (int i = 0; i < postorder_size; ++i) {
      postorder_ind_m[postorder[i]] = i;
    }
    int curr_ind = postorder_size - 1;
    return buildTreeFromNode(inorder, postorder, postorder_ind_m,
                             postorder_size, curr_ind);
  }

private:
  static TreeNode* buildTreeFromNode(
      const std::vector<int>& inorder, const std::vector<int>& postorder,
      const std::unordered_map<int, int>& postorder_ind_m,
      const int& inorder_size, int& curr_ind) {
    TreeNode* curr_node = new TreeNode(inorder[curr_ind--]);
    while (curr_ind >= 0) {
      if (postorder_ind_m.at(curr_node->val) >
          postorder_ind_m.at(inorder[curr_ind])) {
        curr_node->left = buildTreeFromNode(inorder, postorder, postorder_ind_m,
                                            inorder_size, curr_ind);
      } else if (int postorder_ind = postorder_ind_m.at(inorder[curr_ind]);
                 (postorder_ind > 0) &&
                 postorder[postorder_ind - 1] == curr_node->val) {
        TreeNode* new_node = new TreeNode(inorder[curr_ind--]);
        new_node->right = curr_node;
        curr_node = new_node;
      } else {
        return curr_node;
      }
    }
    return curr_node;
  }
};
