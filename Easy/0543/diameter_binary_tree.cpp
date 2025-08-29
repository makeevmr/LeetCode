// Given the root of a binary tree, return the length of the diameter of the
// tree.

#include <utility>
#include <algorithm>

struct TreeNode {
  int val;
  const TreeNode* left;
  const TreeNode* right;

  TreeNode()
      : val(0),
        left(nullptr),
        right(nullptr) {}

  explicit TreeNode(const int& val)
      : val(val),
        left(nullptr),
        right(nullptr) {}

  TreeNode(const int& val, const TreeNode* left, const TreeNode* right)
      : val(val),
        left(left),
        right(right) {}
};

class Solution {
public:
  [[nodiscard]] static int diameterOfBinaryTree(const TreeNode* root) {
    return getSubtreeInfo(root).second;
  }

private:
  [[nodiscard]] static std::pair<int, int> getSubtreeInfo(
      const TreeNode* root) {
    std::pair<int, int> left_subtree_info = {-1, -1};
    std::pair<int, int> right_subtree_info = {-1, -1};
    if (root->left != nullptr) {
      left_subtree_info = getSubtreeInfo(root->left);
    }
    if (root->right != nullptr) {
      right_subtree_info = getSubtreeInfo(root->right);
    }
    int max_path =
        std::max(left_subtree_info.first, right_subtree_info.first) + 1;
    int diameter =
        std::max(std::max(left_subtree_info.second, right_subtree_info.second),
                 left_subtree_info.first + right_subtree_info.first + 2);
    return std::pair<int, int>{max_path, diameter};
  }
};
