/* A path in a binary tree is a sequence of nodes where each pair of adjacent
nodes in the sequence has an edge connecting them. A node can only appear in the
sequence at most once. Note that the path does not need to pass through the
root. The path sum of a path is the sum of the node's values in the path. Given
the root of a binary tree, return the maximum path sum of any non-empty path.
Time complexity: O(n)
Additional memory complexity: O(height of BT)
*/

#include <algorithm>
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
  static int maxPathSum(TreeNode* root) {
    std::pair<int, int> max_paths = calcMaxPath(root);
    return std::max(max_paths.first, max_paths.second);
  }

private:
  static std::pair<int, int> calcMaxPath(const TreeNode* const root) {
    if (root->left == nullptr && root->right == nullptr) {
      return {root->val, root->val};
    }
    std::pair<int, int> left_path({0, 0});
    std::pair<int, int> right_path({0, 0});
    if (root->left != nullptr) {
      left_path = calcMaxPath(root->left);
    }
    if (root->right != nullptr) {
      right_path = calcMaxPath(root->right);
    }
    int subtree_max_path = 0;
    int root_max_path = 0;
    if (root->left != nullptr && root->right != nullptr) {
      root_max_path = std::max({left_path.first + root->val,
                                right_path.first + root->val, root->val});
      subtree_max_path = std::max(
          {left_path.second, right_path.second,
           left_path.first + right_path.first + root->val, root_max_path});
    } else if (root->left != nullptr) {
      root_max_path = root->val;
      if (left_path.first > 0) {
        root_max_path += left_path.first;
      }
      subtree_max_path = std::max(left_path.second, root_max_path);
    } else {
      root_max_path = root->val;
      if (right_path.first > 0) {
        root_max_path += right_path.first;
      }
      subtree_max_path = std::max(right_path.second, root_max_path);
    }
    return {root_max_path, subtree_max_path};
  }
};
