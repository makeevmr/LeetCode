/* You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will
fit in a 32-bit integer.
A leaf node is a node with no children.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) { return sumPaths(root, 0); }

private:
    int sumPaths(TreeNode *root, int current_value) {
        current_value = current_value * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return current_value;
        }
        int left_path_sum = 0;
        int right_path_sum = 0;
        if (root->left != nullptr) {
            left_path_sum = sumPaths(root->left, current_value);
        }
        if (root->right != nullptr) {
            right_path_sum = sumPaths(root->right, current_value);
        }
        return left_path_sum + right_path_sum;
    }
};
