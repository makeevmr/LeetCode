/* Populate each next pointer to point to its next right node. If there is no
next right node, the next pointer should be set to NULL. Initially, all next
pointers are set to NULL. Time complexity: O(n) Additional memory complexity:
O(m), where m is max height of BT Idea: compute max_height, create
vector(tree_height, nullptr) that contains rightmost node on current_level
*/

#include <vector>

// Definition for a Node.
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node()
      : val(0),
        left(nullptr),
        right(nullptr),
        next(nullptr) {}

  Node(int _val)
      : val(_val),
        left(nullptr),
        right(nullptr),
        next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val),
        left(_left),
        right(_right),
        next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    int tree_height = getTreeHeight(root);
    if (tree_height < 2) {
      return root;
    }
    std::vector<Node*> rightmost_on_level(tree_height, nullptr);
    int right_level_node = tree_height - 1;
    connectSubtree(root, rightmost_on_level, right_level_node);
    return root;
  }

private:
  static int getTreeHeight(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    return std::max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
  }

  void connectSubtree(Node* root, std::vector<Node*>& rightmost_on_level,
                      int& level_of_right_node) {
    if (root->left != nullptr) {
      --level_of_right_node;
      connectSubtree(root->left, rightmost_on_level, level_of_right_node);
      ++level_of_right_node;
    }
    if (root->right != nullptr) {
      --level_of_right_node;
      connectSubtree(root->right, rightmost_on_level, level_of_right_node);
      ++level_of_right_node;
    }
    if (rightmost_on_level[level_of_right_node] != nullptr) {
      rightmost_on_level[level_of_right_node]->next = root;
    }
    rightmost_on_level[level_of_right_node] = root;
  }
};
