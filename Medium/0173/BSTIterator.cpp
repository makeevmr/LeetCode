/* Implement the BSTIterator class that represents an iterator over the in-order traversal of a
binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is
given as part of the constructor. The pointer should be initialized to a non-existent number smaller
than any element in the BST. boolean hasNext() Returns true if there exists a number in the
traversal to the right of the pointer, otherwise returns false. int next() Moves the pointer to the
right, then returns the number at the pointer. Notice that by initializing the pointer to a
non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number
in the in-order traversal when next() is called.
Time complexity: O(n), where n is number of operations
Additional memory complexity: O(height of tree)
*/

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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *curr_node = root;
        while (curr_node != nullptr) {
            curr_path.push_back(curr_node);
            curr_node = curr_node->left;
        }
        TreeNode *imaginary_node = new TreeNode(-1);
        curr_path.back()->left = imaginary_node;
        curr_path.push_back(imaginary_node);
    }

    int next() {
        if (TreeNode *curr_node = curr_path.back()->right; curr_node != nullptr) {
            curr_path.push_back(curr_node);
            while (curr_node->left != nullptr) {
                curr_node = curr_node->left;
                curr_path.push_back(curr_node);
            }
        } else {
            bool is_next_found = false;
            do {
                int parent = static_cast<int>(curr_path.size()) - 2;
                is_next_found = curr_path[parent]->left == curr_path[parent + 1];
                curr_path.pop_back();
            } while (!is_next_found);
        }
        return curr_path.back()->val;
    }

    bool hasNext() {
        if (curr_path.back()->right != nullptr) {
            return true;
        }
        for (int i = static_cast<int>(curr_path.size()) - 2; i >= 0; --i) {
            if (curr_path[i]->left == curr_path[i + 1]) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<TreeNode *> curr_path;
};
