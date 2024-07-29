/* Given the root of a binary tree, return the average value of the nodes on each level in the form
of an array. Answers within 10-5 of the actual answer will be accepted.
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

class Solution {
public:
    static std::vector<double> averageOfLevels(TreeNode *root) {
        std::vector<long long int> level_sum;
        std::vector<long long int> level_counter;
        calcSum(root, level_sum, level_counter, 0);
        std::vector<double> average_on_level;
        for (std::size_t i = 0, level_sum_size = level_sum.size(); i < level_sum_size; ++i) {
            average_on_level.push_back(static_cast<double>(level_sum[i]) /
                                       static_cast<double>(level_counter[i]));
        }
        return average_on_level;
    }

private:
    static void calcSum(const TreeNode *const root, std::vector<long long int> &level_sum,
                        std::vector<long long int> &level_counter, std::size_t curr_level) {
        if (root == nullptr) {
            return;
        }
        if (level_sum.size() == curr_level) {
            level_sum.push_back(static_cast<long long int>(root->val));
            level_counter.push_back(1);
        } else {
            level_sum[curr_level] += static_cast<long long int>(root->val);
            ++level_counter[curr_level];
        }
        calcSum(root->left, level_sum, level_counter, curr_level + 1);
        calcSum(root->right, level_sum, level_counter, curr_level + 1);
    }
};