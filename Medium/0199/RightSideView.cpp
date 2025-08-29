/* Given the root of a binary tree, imagine yourself standing on the right side
of it, return the values of the nodes you can see ordered from top to bottom.
*/

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
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> ans;
    fillRightSide(root, ans, 0);
    return ans;
  }

private:
  void fillRightSide(TreeNode* root, std::vector<int>& ans, int curr_level) {
    if (root == nullptr) {
      return;
    }
    if (curr_level == static_cast<int>(ans.size())) {
      ans.push_back(root->val);
    } else {
      ans[curr_level] = root->val;
    }
    fillRightSide(root->left, ans, curr_level + 1);
    fillRightSide(root->right, ans, curr_level + 1);
  }
};
