/* Given an integer array nums where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree. Time complexity: O(n)
Additional memory complexity: O(log(nums.size()))
Idea: use Divide & Conquer idea
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
  explicit TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x),
        left(left),
        right(right) {}
};

#include <vector>

class Solution {
public:
  static TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return createSubtree(nums, 0, static_cast<int>(nums.size() - 1));
  }

private:
  static TreeNode* createSubtree(const std::vector<int>& nums, int left,
                                 int right) {
    if (left > right) {
      return nullptr;
    }
    int middle = (left + right) / 2 + (left + right) % 2;
    TreeNode* root = new TreeNode(nums[middle]);
    root->left = createSubtree(nums, left, middle - 1);
    root->right = createSubtree(nums, middle + 1, right);
    return root;
  }
};
