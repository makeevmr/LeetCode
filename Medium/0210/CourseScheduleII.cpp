/* There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course bi first if you want to take course
ai. For example, the pair [0, 1], indicates that to take course 0 you have to
first take course 1. Return the ordering of courses you should take to finish
all courses. If there are many valid answers, return any of them. If it is
impossible to finish all courses, return an empty array. Time complexity: O(V +
E) Additional memory complexity: O(V + E) Idea: use DFS algorithm to find cycles
in graph and topological sort
*/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
  static std::vector<int> findOrder(
      int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::unordered_set<int>> adjacency_list;
    fillGraph(adjacency_list, prerequisites);
    std::vector<int> visited_nodes(numCourses, 0);
    std::vector<int> topological_sort;
    bool cycle_found = false;
    for (int i = 0; i < numCourses; ++i) {
      if (visited_nodes[i] == 0) {
        if (topologicalSortDFS(adjacency_list, visited_nodes, topological_sort,
                               i)) {
          cycle_found = true;
          break;
        }
      }
    }
    if (cycle_found) {
      return {};
    }
    std::reverse(topological_sort.begin(), topological_sort.end());
    return topological_sort;
  }

private:
  static void fillGraph(
      std::unordered_map<int, std::unordered_set<int>>& adjacency_list,
      const std::vector<std::vector<int>>& prerequisites) {
    for (std::size_t i = 0; i < prerequisites.size(); ++i) {
      adjacency_list[prerequisites[i][1]].insert(prerequisites[i][0]);
    }
  }

  // return true if there is a cycle in graph, false otherwise
  static bool topologicalSortDFS(
      const std::unordered_map<int, std::unordered_set<int>>& adjacency_list,
      std::vector<int>& visited_nodes, std::vector<int>& topological_sort,
      int node) {
    visited_nodes[node] = 1;
    if (auto f_iter = adjacency_list.find(node);
        f_iter != adjacency_list.end()) {
      for (const auto& descendant : f_iter->second) {
        if (visited_nodes[descendant] == 1) {
          return true;
        }
        if ((visited_nodes[descendant] == 0) &&
            (topologicalSortDFS(adjacency_list, visited_nodes, topological_sort,
                                descendant))) {
          return true;
        }
      }
    }
    topological_sort.push_back(node);
    visited_nodes[node] = 2;
    return false;
  }
};
