/* Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides,
each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice
that you can assign the val to True or False when isLeaf is False, and both are accepted in the
answer. isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
Time complexity: O(n ^ 2 * log(n))
Additional memory complexity: O(log(n))
Idea: if square is not leaf node create 4 descendants, and check them recursively
*/

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool val, bool is_leaf) {
        val = val;
        isLeaf = is_leaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool val, bool is_leaf, Node* top_left, Node* top_right, Node* bottom_left,
         Node* bottom_right) {
        val = val;
        isLeaf = is_leaf;
        topLeft = top_left;
        topRight = top_right;
        bottomLeft = bottom_left;
        bottomRight = bottom_right;
    }
};

#include <vector>

class Solution {
public:
    static Node* construct(const std::vector<std::vector<int>>& grid) {
        int grid_size = static_cast<int>(grid.size());
        return constructTree(grid, std::pair<int, int>{0, 0},
                             std::pair<int, int>{grid_size, grid_size});
    }

private:
    [[nodiscard]] static bool isLeaf(const std::vector<std::vector<int>>& grid,
                                     const std::pair<int, int>& top_left,
                                     const std::pair<int, int>& bot_right) {
        int value = grid[top_left.second][top_left.first];
        for (int i = top_left.second; i < bot_right.second; ++i) {
            for (int j = top_left.first; j < bot_right.first; ++j) {
                if (value != grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    static Node* constructTree(const std::vector<std::vector<int>>& grid,
                               std::pair<int, int> top_left, std::pair<int, int> bot_right) {
        Node* root = new Node();
        root->isLeaf = isLeaf(grid, top_left, bot_right);
        if (!root->isLeaf) {
            int x_cent = (top_left.first + bot_right.first) / 2;
            int y_cent = (top_left.second + bot_right.second) / 2;
            root->topLeft = constructTree(grid, top_left, std::pair<int, int>{x_cent, y_cent});
            root->topRight = constructTree(grid, std::pair<int, int>{x_cent, top_left.second},
                                           std::pair<int, int>{bot_right.first, y_cent});
            root->bottomLeft = constructTree(grid, std::pair<int, int>{top_left.first, y_cent},
                                             std::pair<int, int>{x_cent, bot_right.second});
            root->bottomRight = constructTree(grid, std::pair<int, int>{x_cent, y_cent}, bot_right);
        } else {
            root->val = static_cast<bool>(grid[top_left.second][top_left.first]);
        }
        return root;
    }
};

int main() {
    const std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
    Solution::construct(grid);
    return 0;
}
