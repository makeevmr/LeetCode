/* Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
*/

#include <iostream>
#include <vector>

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  static Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    std::vector<Node*> nodes(101, nullptr);
    DFSGraphCopy(node, nodes);
    return nodes[node->val];
  }

private:
  static void DFSGraphCopy(Node* node, std::vector<Node*>& nodes) {
    Node* curr_node = new Node(node->val);
    nodes[node->val] = curr_node;
    for (auto b_iter = node->neighbors.begin(), e_iter = node->neighbors.end();
         b_iter != e_iter; ++b_iter) {
      if (!nodes[(*b_iter)->val]) {
        DFSGraphCopy(*b_iter, nodes);
      }
    }
    for (auto b_iter = node->neighbors.begin(), e_iter = node->neighbors.end();
         b_iter != e_iter; ++b_iter) {
      curr_node->neighbors.push_back(nodes[(*b_iter)->val]);
    }
  }
};
