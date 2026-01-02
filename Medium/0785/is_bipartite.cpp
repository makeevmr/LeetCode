#include <vector>
#include <queue>

class Solution {
public:
  [[nodiscard]] static bool isBipartite(
      const std::vector<std::vector<int>>& graph) {
    return isBipartiteBFS(graph);
  }

private:
  enum class NodeType {
    UNDEFINED,
    TYPE_A,
    TYPE_B,
  };

  [[nodiscard]] static bool isBipartiteBFS(
      const std::vector<std::vector<int>>& graph) {
    const std::size_t nodes = graph.size();
    std::vector<NodeType> node_types(nodes, NodeType::UNDEFINED);
    for (std::size_t node = 0; node < nodes; ++node) {
      if (node_types[node] == NodeType::UNDEFINED) {
        NodeType curr_type = NodeType::TYPE_A;
        std::queue<std::size_t> nodes_queue;
        nodes_queue.push(node);
        node_types[node] = curr_type;
        while (!nodes_queue.empty()) {
          const std::size_t queue_size = nodes_queue.size();
          for (std::size_t i = 0; i < queue_size; ++i) {
            const std::size_t new_node = nodes_queue.front();
            nodes_queue.pop();
            for (const int& adj_node : graph[new_node]) {
              switch (node_types[adj_node]) {
                case NodeType::UNDEFINED:
                  if (curr_type == NodeType::TYPE_A) {
                    node_types[adj_node] = NodeType::TYPE_B;
                  } else {
                    node_types[adj_node] = NodeType::TYPE_A;
                  }
                  nodes_queue.push(static_cast<std::size_t>(adj_node));
                  break;
                default:
                  if (node_types[adj_node] == curr_type) {
                    return false;
                  }
                  break;
              }
            }
          }
          if (curr_type == NodeType::TYPE_A) {
            curr_type = NodeType::TYPE_B;
          } else {
            curr_type = NodeType::TYPE_A;
          }
        }
      }
    }
    return true;
  }
};