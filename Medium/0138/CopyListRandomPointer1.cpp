/* A linked list of length n is given such that each node contains an additional random pointer,
which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where
each new node has its value set to the value of its corresponding original node. Both the next and
random pointer of the new nodes should point to new nodes in the copied list such that the pointers
in the original list and copied list represent the same list state. None of the pointers in the new
list should point to nodes in the original list.
Time complexity: O(n)
Additional memory complexity: O(1)
Idea: Tie the list in alternating nodes from different lists
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
    static Node *copyRandomList(Node *head) {
        bool is_head_node = true;
        Node *head_cpy = nullptr;
        Node *orig_list_node = head;
        while (orig_list_node != nullptr) {
            Node *new_node = new Node(orig_list_node->val);
            new_node->next = orig_list_node->next;
            orig_list_node->next = new_node;
            orig_list_node = orig_list_node->next->next;
            if (is_head_node) {
                head_cpy = new_node;
                is_head_node = false;
            }
        }
        orig_list_node = head;
        while (orig_list_node != nullptr) {
            Node *copy_list_node = orig_list_node->next;
            Node *next_node = copy_list_node->next;
            if (orig_list_node->random == nullptr) {
                copy_list_node->random = nullptr;
            } else {
                copy_list_node->random = orig_list_node->random->next;
            }
            orig_list_node = next_node;
            if (is_head_node) {
                head_cpy = copy_list_node;
                is_head_node = false;
            }
        }
        orig_list_node = head;
        while (orig_list_node != nullptr) {
            Node *copy_list_node = orig_list_node->next;
            Node *next_node = copy_list_node->next;
            orig_list_node->next = next_node;
            if (next_node != nullptr) {
                copy_list_node->next = next_node->next;
            }
            orig_list_node = next_node;
        }
        return head_cpy;
    }
};
