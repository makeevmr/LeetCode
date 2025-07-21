// Given the root of a binary tree and an integer targetSum, return the number
// of paths where the sum of the values along the path equals targetSum.

#include <cstdint>
#include <vector>

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

class Solution {
public:
    [[nodiscard]] static int pathSum(TreeNode* root, int target_sum) {
        if (root == nullptr) {
            return 0;
        }
        std::uint64_t total_paths = 0;
        std::int64_t target_sum_64 = static_cast<std::int64_t>(target_sum);
        std::vector<TreeNode*> curr_path;
        TreeNode* curr_node = root;
        curr_path.push_back(curr_node);
        while (curr_node->left != nullptr) {
            curr_node = curr_node->left;
            curr_path.push_back(curr_node);
        }
        total_paths += calcPaths(curr_path, target_sum_64);
        while (curr_node != nullptr) {
            curr_node = getNextNode(curr_node, curr_path);
            if (curr_node != nullptr) {
                total_paths += calcPaths(curr_path, target_sum_64);
            }
        }
        return static_cast<int>(total_paths);
    }

private:
    [[nodiscard]] static TreeNode* getNextNode(
        TreeNode* curr_node, std::vector<TreeNode*>& curr_path) {
        if (curr_node->right != nullptr) {
            curr_node = curr_node->right;
            curr_path.push_back(curr_node);
            while (curr_node->left != nullptr) {
                curr_node = curr_node->left;
                curr_path.push_back(curr_node);
            }
            return curr_node;
        }
        curr_path.pop_back();
        while (!curr_path.empty() && curr_path.back()->right == curr_node) {
            curr_node = curr_path.back();
            curr_path.pop_back();
        }
        if (curr_path.empty()) {
            return nullptr;
        }
        curr_node = curr_path.back();
        return curr_node;
    }

    [[nodiscard]] static std::uint64_t calcPaths(
        const std::vector<TreeNode*>& curr_path, std::int64_t target_sum) {
        std::uint64_t path_counter = 0;
        std::int64_t curr_sum = 0;
        for (auto iter = curr_path.crbegin(); iter != curr_path.crend();
             ++iter) {
            curr_sum += static_cast<std::int64_t>((*iter)->val);
            if (curr_sum == target_sum) {
                ++path_counter;
            }
        }
        return path_counter;
    }
};
