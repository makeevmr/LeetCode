/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a
binary tree and inorder is the inorder traversal of the same tree, construct and return the
binary tree.
Time complexity: O(n)
Additional memory complexity: O(max height of BST)
*/

#include <iostream>
#include <unordered_map>
#include <vector>

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
    static TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        std::unordered_map<int, int> preorder_ind_m;
        int preorder_size = static_cast<int>(preorder.size());
        for (int i = 0; i < preorder_size; ++i) {
            preorder_ind_m[preorder[i]] = i;
        }
        int curr_ind = 0;
        return buildTreeFromNode(preorder, inorder, preorder_ind_m, preorder_size, curr_ind);
    }

private:
    static TreeNode *buildTreeFromNode(const std::vector<int> &preorder,
                                       const std::vector<int> &inorder,
                                       const std::unordered_map<int, int> &preorder_ind_m,
                                       const int &inorder_size, int &curr_ind) {
        TreeNode *curr_node = new TreeNode(inorder[curr_ind++]);
        while (curr_ind < inorder_size) {
            if (preorder_ind_m.at(curr_node->val) < preorder_ind_m.at(inorder[curr_ind])) {
                curr_node->right =
                    buildTreeFromNode(preorder, inorder, preorder_ind_m, inorder_size, curr_ind);
            } else if (int preorder_ind = preorder_ind_m.at(inorder[curr_ind]);
                       (preorder_ind < inorder_size - 1) &&
                       preorder[preorder_ind + 1] == curr_node->val) {
                TreeNode *new_node = new TreeNode(inorder[curr_ind++]);
                new_node->left = curr_node;
                curr_node = new_node;
            } else {
                return curr_node;
            }
        }
        return curr_node;
    }
};
