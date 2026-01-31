#include <vector>
#include <set>
#include <queue>

class Solution {
public:
  [[nodiscard]] static std::vector<int> sumOfDistancesInTree(
      int n, const std::vector<std::vector<int>>& edges) {
    const int start_node = 0;
    std::vector<std::set<int>> adj_list = createAdjList(edges, n);
    std::vector<int> subtree_sizes(n, 0);
    fillSubtreeSizesDFS(adj_list, subtree_sizes, start_node);
    std::vector<int> distance_sums(n, 0);
    const int start_sum = getDistanceSumFromNodeBFS(adj_list, start_node);
    fillDistanceSumsDFS(adj_list, subtree_sizes, distance_sums, n, start_node,
                        start_sum);
    return distance_sums;
  }

private:
  [[nodiscard]] static std::vector<std::set<int>> createAdjList(
      const std::vector<std::vector<int>>& edges, const int& nodes) {
    std::vector<std::set<int>> adj_list(nodes);
    for (const auto& edge : edges) {
      adj_list[edge[0]].insert(edge[1]);
      adj_list[edge[1]].insert(edge[0]);
    }
    return adj_list;
  }

  static void fillSubtreeSizesDFS(const std::vector<std::set<int>>& adj_list,
                                  std::vector<int>& subtree_sizes,
                                  const int& root_node) {
    ++subtree_sizes[root_node];
    for (const int& adj_node : adj_list[root_node]) {
      if (subtree_sizes[adj_node] == 0) {
        fillSubtreeSizesDFS(adj_list, subtree_sizes, adj_node);
        subtree_sizes[root_node] += subtree_sizes[adj_node];
      }
    }
  }

  [[nodiscard]] static int getDistanceSumFromNodeBFS(
      const std::vector<std::set<int>>& adj_list, const int& start_node) {
    int total_dist_sum = 0;
    int curr_dist = 0;
    std::queue<int> nodes_queue;
    std::vector<bool> visited_nodes(adj_list.size(), false);
    nodes_queue.push(start_node);
    visited_nodes[start_node] = true;
    while (!nodes_queue.empty()) {
      int nodes_on_level = static_cast<int>(nodes_queue.size());
      total_dist_sum += curr_dist * nodes_on_level;
      while (nodes_on_level > 0) {
        int new_node = nodes_queue.front();
        nodes_queue.pop();
        for (const int& adj_node : adj_list[new_node]) {
          if (!visited_nodes[adj_node]) {
            nodes_queue.push(adj_node);
            visited_nodes[adj_node] = true;
          }
        }
        --nodes_on_level;
      }
      ++curr_dist;
    }
    return total_dist_sum;
  }

  static void fillDistanceSumsDFS(const std::vector<std::set<int>>& adj_list,
                                  const std::vector<int>& subtree_sizes,
                                  std::vector<int>& distance_sums,
                                  const int& total_nodes, const int& curr_node,
                                  const int curr_sum) {
    distance_sums[curr_node] = curr_sum;
    for (const int& adj_node : adj_list[curr_node]) {
      if (distance_sums[adj_node] == 0) {
        fillDistanceSumsDFS(
            adj_list, subtree_sizes, distance_sums, total_nodes, adj_node,
            curr_sum + total_nodes - 2 * subtree_sizes[adj_node]);
      }
    }
  }
};