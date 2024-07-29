/* Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the
values of any two different nodes in the tree. */

#include <numeric>
#include <stack>

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
    static int getMinimumDifference(TreeNode *root) {
        std::stack<TreeNode *> curr_path;
        TreeNode *curr_node = getLeftMostNode(root, curr_path);
        TreeNode *next_node = next(curr_path);
        int min_diff = std::numeric_limits<int>::max();
        while (next_node != nullptr) {
            if (int new_diff = next_node->val - curr_node->val; new_diff < min_diff) {
                min_diff = new_diff;
            }
            curr_node = next_node;
            next_node = next(curr_path);
        }
        return min_diff;
    }

private:
    static TreeNode *getLeftMostNode(TreeNode *root, std::stack<TreeNode *> &curr_path) {
        TreeNode *curr_node = root;
        while (curr_node != nullptr) {
            curr_path.push(curr_node);
            curr_node = curr_node->left;
        }
        return curr_path.top();
    }

    static TreeNode *next(std::stack<TreeNode *> &curr_path) {
        if (TreeNode *curr_node = curr_path.top()->right; curr_node != nullptr) {
            curr_path.push(curr_node);
            while (curr_node->left != nullptr) {
                curr_node = curr_node->left;
                curr_path.push(curr_node);
            }
        } else {
            bool is_next_found = false;
            do {
                TreeNode *curr_node = curr_path.top();
                curr_path.pop();
                if (!curr_path.empty()) {
                    is_next_found = curr_path.top()->left == curr_node;
                }
            } while (!is_next_found && !curr_path.empty());
        }
        if (curr_path.empty()) {
            curr_path.push(nullptr);
        }
        return curr_path.top();
    }
};
