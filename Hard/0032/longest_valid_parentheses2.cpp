// Given a string containing just the characters '(' and ')', return the length
// of the longest valid (well-formed) parentheses.

#include <iostream>

#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
#include <queue>

class Solution {
public:
    [[nodiscard]] static int longestValidParentheses(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        std::vector<int> balance_array;
        const std::size_t s_size = s.size();
        balance_array.reserve(s_size);
        int curr_balance = 0;
        for (std::size_t i = 0; i < s_size; ++i) {
            if (s[i] == '(') {
                ++curr_balance;
            } else {
                --curr_balance;
            }
            balance_array.push_back(curr_balance);
        }
        SimpleSegmentTree<int, MinOperation, std::numeric_limits<int>::max()>
            segment_tree(balance_array);
        int answer = 0;
        std::unordered_map<int, std::queue<int>> balance_map;
        balance_map[0].push(-1);
        int balance_array_size = static_cast<int>(balance_array.size());
        for (int i = 0; i < balance_array_size; ++i) {
            int new_balance = balance_array[i];
            if (auto f_iter = balance_map.find(new_balance);
                f_iter != balance_map.end()) {
                std::queue<int>& balance_queue = f_iter->second;
                while (!balance_queue.empty() &&
                       (segment_tree.segmentQuery(balance_queue.front() + 1,
                                                  i) < new_balance)) {
                    balance_queue.pop();
                }
                if (!balance_queue.empty()) {
                    answer = std::max(answer, i - balance_queue.front());
                }
            }
            balance_map[new_balance].push(i);
        }
        return answer;
    }

private:
    template <typename T, typename BinaryOperation, T kNeutralElement>
    class SimpleSegmentTree {
    public:
        explicit SimpleSegmentTree(const std::vector<T>& base_array)
            : bin_operation_(),
              base_array_size_(base_array.size()),
              segment_tree_(4 * base_array.size()) {
            if (!base_array.empty()) {
                build(base_array, 0ULL, 0ULL, base_array.size() - 1);
            }
        }

        T segmentQuery(const size_t& left, const size_t& right) {
            if (base_array_size_ == 0ULL) {
                return kNeutralElement;
            }
            return calcSubtree(0ULL, 0ULL, base_array_size_ - 1, left, right);
        }

    private:
        void build(const std::vector<T>& base_array, const size_t& vertex_ind,
                   const size_t& left, const size_t& right) {
            if (left == right) {
                segment_tree_[vertex_ind] = base_array[left];
            } else {
                const size_t& middle_vertex_ind = (left + right) / 2;
                const size_t left_child = vertex_ind * 2 + 1;
                const size_t right_child = vertex_ind * 2 + 2;
                build(base_array, left_child, left, middle_vertex_ind);
                build(base_array, right_child, middle_vertex_ind + 1, right);
                segment_tree_[vertex_ind] = bin_operation_(
                    segment_tree_[left_child], segment_tree_[right_child]);
            }
        }

        T calcSubtree(const size_t& vertex_ind, const size_t& segment_left,
                      const size_t& segment_right, const size_t& query_left,
                      const size_t& query_right) {
            if (query_left > query_right) {
                return kNeutralElement;
            }
            if ((segment_left == query_left) &&
                (segment_right == query_right)) {
                return segment_tree_[vertex_ind];
            }
            const size_t& segment_middle = (segment_left + segment_right) / 2;
            const size_t left_child = vertex_ind * 2 + 1;
            const size_t right_child = vertex_ind * 2 + 2;
            return bin_operation_(
                calcSubtree(left_child, segment_left, segment_middle,
                            query_left, std::min(query_right, segment_middle)),
                calcSubtree(right_child, segment_middle + 1, segment_right,
                            std::max(query_left, segment_middle + 1),
                            query_right));
        }

        BinaryOperation bin_operation_;
        size_t base_array_size_;
        std::vector<T> segment_tree_;
    };

    struct MinOperation {
        int operator()(const int& left, const int& right) const {
            return std::min(left, right);
        }
    };
};

int main() {
    // std::string s = "(()";
    // std::string s = ")()())";
    // std::string s = "";
    // std::string s = "()";
    std::string s = ")(";
    std::cout << Solution::longestValidParentheses(s) << '\n';
    return 0;
}
