/* Given the roots of two binary trees p and q, write a function to check if they are the same or
not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the
same value.
Time complexity: O(n)
Additional memory complexity: O(min(depth of tree1, depth of tree2))
Idea: use forward tree traversal
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
    static bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if ((p && !q) || (!p && q)) {
            return false;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
