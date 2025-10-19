#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
private:
  struct PathsFromNode;

public:
  [[nodiscard]] static std::vector<int> maxTargetNodes(
      const std::vector<std::vector<int>>& edges1,
      const std::vector<std::vector<int>>& edges2) {
    std::vector<PathsFromNode> paths1_from_node =
        getEvenOddPaths(createAdjList(edges1));
    std::vector<PathsFromNode> paths2_from_node =
        getEvenOddPaths(createAdjList(edges2));
    int max_odd_paths2 = -1;
    for (const auto& [_, odd] : paths2_from_node) {
      max_odd_paths2 = std::max(max_odd_paths2, odd);
    }
    std::vector<int> answer;
    for (const auto& [even, odd] : paths1_from_node) {
      answer.push_back(even + max_odd_paths2);
    }
    return answer;
  }

private:
  [[nodiscard]] static std::vector<PathsFromNode> getEvenOddPaths(
      const std::unordered_map<int, std::vector<int>>& adj_list) {
    const int start_node = 0;
    std::vector<PathsFromNode> paths_from_node(
        adj_list.size(), PathsFromNode{.even_ = -1, .odd_ = -1});
    PathsFromNode& start_node_paths = paths_from_node[start_node];
    start_node_paths.even_ = 1;
    start_node_paths.odd_ = 0;
    for (const int& adj_node : adj_list.at(start_node)) {
      if (paths_from_node[adj_node].even_ == -1) {
        start_node_paths +=
            getDFSPathsForSubtree(adj_list, paths_from_node, adj_node);
      }
    }
    updateBFSPathsForTree(adj_list, paths_from_node, start_node);
    return paths_from_node;
  }

  [[nodiscard]] static std::unordered_map<int, std::vector<int>> createAdjList(
      const std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::vector<int>> adj_list;
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }
    return adj_list;
  }

  [[nodiscard]] static PathsFromNode getDFSPathsForSubtree(
      const std::unordered_map<int, std::vector<int>>& adj_list,
      std::vector<PathsFromNode>& paths_from_node, const int& root_node) {
    PathsFromNode& root_node_paths = paths_from_node[root_node];
    root_node_paths.even_ = 1;
    root_node_paths.odd_ = 0;
    for (const int& adj_node : adj_list.at(root_node)) {
      if (paths_from_node[adj_node].even_ == -1) {
        root_node_paths +=
            getDFSPathsForSubtree(adj_list, paths_from_node, adj_node);
      }
    }
    return PathsFromNode{.even_ = root_node_paths.odd_,
                         .odd_ = root_node_paths.even_};
  }

  static void updateBFSPathsForTree(
      const std::unordered_map<int, std::vector<int>>& adj_list,
      std::vector<PathsFromNode>& paths_from_node, const int& start_node) {
    std::queue<int> nodes_queue;
    std::vector<bool> is_node_marked(adj_list.size(), false);
    nodes_queue.push(start_node);
    is_node_marked[start_node] = true;
    PathsFromNode& start_node_paths = paths_from_node[start_node];
    PathsFromNode curr_paths = {.even_ = start_node_paths.odd_,
                                .odd_ = start_node_paths.even_};
    while (!nodes_queue.empty()) {
      curr_paths = {.even_ = curr_paths.odd_, .odd_ = curr_paths.even_};
      const std::size_t queue_size = nodes_queue.size();
      for (std::size_t i = 0; i < queue_size; ++i) {
        int queue_node = nodes_queue.front();
        nodes_queue.pop();
        paths_from_node[queue_node] = curr_paths;
        for (const int& adj_node : adj_list.at(queue_node)) {
          if (!is_node_marked[adj_node]) {
            is_node_marked[adj_node] = true;
            nodes_queue.push(adj_node);
          }
        }
      }
    }
  }

  struct PathsFromNode {
    int even_;
    int odd_;

    PathsFromNode& operator+=(const PathsFromNode& other) & noexcept {
      even_ += other.even_;
      odd_ += other.odd_;
      return *this;
    }
  };
};