/* Given the root of a binary search tree, and an integer k, return the kth smallest value
(1-indexed) of all the values of the nodes in the tree.
Time complexity: O(n)
Additional memory complexity: O(height of BST)
Idea: find leftmost node and then use getNextNode while k > 0
*/

#include <iostream>
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
    [[nodiscard]] static int kthSmallest(TreeNode *root, int k) {
        std::stack<const TreeNode *> curr_path;
        const TreeNode *curr_node = getMinNode(root, curr_path);
        --k;
        while (k > 0) {
            curr_node = getNextNode(curr_node, curr_path);
            --k;
        }
        return curr_node->val;
    }

private:
    [[nodiscard]] static const TreeNode *getMinNode(const TreeNode *root,
                                                    std::stack<const TreeNode *> &curr_path) {
        while (root->left != nullptr) {
            curr_path.push(root);
            root = root->left;
        }
        return root;
    }

    [[nodiscard]] static const TreeNode *getNextNode(const TreeNode *curr_node,
                                                     std::stack<const TreeNode *> &curr_path) {
        if (curr_node->right != nullptr) {
            curr_path.push(curr_node);
            curr_node = curr_node->right;
            while (curr_node->left != nullptr) {
                curr_path.push(curr_node);
                curr_node = curr_node->left;
            }
        } else {
            bool is_left_child = false;
            while (!is_left_child) {
                is_left_child = curr_path.top()->left == curr_node;
                curr_node = curr_path.top();
                curr_path.pop();
            }
        }
        return curr_node;
    }
};
