/* Given the root of a complete binary tree, return the number of the nodes in
the tree.

According to Wikipedia, every level, except possibly the last, is completely
filled in a complete binary tree, and all nodes in the last level are as far
left as possible. It can have between 1 and 2h nodes inclusive at the last level
h.

Design an algorithm that runs in less than O(n) time complexity.
Time complexity: O(log(N) * log(N)), where N is number of nodes in tree
Additional memory complexity: O(1)
Idea: use binary representation of unsigned int to choose path in bynary search
(0 is left branch, 1 is right branch)
*/

#include <cmath>

struct TreeNode {
public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode()
      : val(0),
        left(nullptr),
        right(nullptr) {}

  TreeNode(int val)
      : val(val),
        left(nullptr),
        right(nullptr) {}

  TreeNode(int val, TreeNode* left, TreeNode* right)
      : val(val),
        left(left),
        right(right) {}
};

class Solution {
public:
  static int countNodes(TreeNode* root) {
    int right_levels = getRightLevels(root);
    int left_levels = getLeftLevels(root);
    if (left_levels == right_levels) {
      return std::pow(2, left_levels) - 1;
    }
    int nodes_counter = std::pow(2, right_levels) - 1;
    unsigned int left_search = 0;
    unsigned int right_search = std::pow(2, right_levels - 1);
    bool is_level_edge_found = false;
    while (left_search < right_search - 1) {
      int curr_digit = right_levels - 2;
      TreeNode* curr_node = root;
      unsigned int middle = (left_search + right_search) >> 1;
      while (curr_digit >= 0) {
        if (middle & (1 << curr_digit)) {
          curr_node = curr_node->right;
        } else {
          curr_node = curr_node->left;
        }
        --curr_digit;
      }
      if (curr_node->left != nullptr && curr_node->right == nullptr) {
        nodes_counter += 2 * middle + 1;
        is_level_edge_found = true;
        break;
      }
      if (curr_node->left == nullptr) {
        right_search = middle;
      } else {
        left_search = middle;
      }
    }
    if (!is_level_edge_found) {
      nodes_counter += (left_search + 1) * 2;
      int curr_digit = right_levels - 2;
      TreeNode* curr_node = root;
      while (curr_digit >= 0) {
        if (left_search & (1 << curr_digit)) {
          curr_node = curr_node->right;
        } else {
          curr_node = curr_node->left;
        }
        --curr_digit;
      }
      if (curr_node->right == nullptr) {
        --nodes_counter;
      }
    }
    return nodes_counter;
  }

private:
  static int getRightLevels(const TreeNode* root) {
    int levels_counter = 0;
    while (root != nullptr) {
      ++levels_counter;
      root = root->right;
    }
    return levels_counter;
  }

  static int getLeftLevels(const TreeNode* root) {
    int levels_counter = 0;
    while (root != nullptr) {
      ++levels_counter;
      root = root->left;
    }
    return levels_counter;
  }
};