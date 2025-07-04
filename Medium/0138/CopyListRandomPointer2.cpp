/* A linked list of length n is given such that each node contains an additional random pointer,
which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where
each new node has its value set to the value of its corresponding original node. Both the next and
random pointer of the new nodes should point to new nodes in the copied list such that the pointers
in the original list and copied list represent the same list state. None of the pointers in the new
list should point to nodes in the original list.
Time complexity: O(n)
Additional memory complexity: O(n)
Idea: use unordered_map<Node *, int> to store relative indexes of nodes, use vector to store
relative pointers for each node
*/

#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    static Node *copyRandomList(const Node *head) {
        std::unordered_map<const Node *, int> relative_ind_orig;
        std::unordered_map<int, Node *> relative_ind_copy;
        const Node *curr_node_orig = head;
        Node *curr_node_copy = nullptr;
        Node *head_cpy = nullptr;
        int curr_index = 0;
        bool is_head_iter = true;
        while (curr_node_orig != nullptr) {
            Node *new_node = new Node(curr_node_orig->val);
            relative_ind_orig.insert({curr_node_orig, curr_index});
            relative_ind_copy.insert({curr_index, new_node});
            if (is_head_iter) {
                head_cpy = new_node;
                is_head_iter = false;
            } else {
                curr_node_copy->next = new_node;
            }
            curr_node_copy = new_node;
            curr_node_orig = curr_node_orig->next;
            ++curr_index;
        }
        std::vector<int> random_ptrs(relative_ind_orig.size());
        curr_node_orig = head;
        curr_index = 0;
        while (curr_node_orig != nullptr) {
            random_ptrs[curr_index] = relative_ind_orig.contains(curr_node_orig->random)
                                          ? relative_ind_orig[curr_node_orig->random]
                                          : -1;
            curr_node_orig = curr_node_orig->next;
            ++curr_index;
        }
        curr_node_copy = head_cpy;
        curr_index = 0;
        while (curr_node_copy != nullptr) {
            if (random_ptrs[curr_index] == -1) {
                curr_node_copy->random = nullptr;
            } else {
                curr_node_copy->random = relative_ind_copy[random_ptrs[curr_index]];
            }
            ++curr_index;
            curr_node_copy = curr_node_copy->next;
        }
        return head_cpy;
    }
};

int main() {
    Node *head = new Node(7);
    Node *first = new Node(13);
    Node *second = new Node(11);
    Node *third = new Node(10);
    Node *fourth = new Node(1);
    head->next = first;
    first->next = second;
    first->random = head;
    second->next = third;
    second->random = fourth;
    third->next = fourth;
    third->random = second;
    fourth->random = head;
    Node *head_cpy = Solution::copyRandomList(head);
    return 0;
}
