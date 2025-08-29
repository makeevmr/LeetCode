/* You are given an array of variable pairs equations and an array of real
numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single
variable. You are also given some queries, where queries[j] = [Cj, Dj]
represents the jth query where you must find the answer for Cj / Dj = ?. Return
the answers to all queries. If a single answer cannot be determined, return
-1.0. Time complexity: O(Q * (E + V)), where Q is number of queries, E - edges,
V - vertices in graph Memory complexity: O(V^2) Idea: use biderectional graph to
represent all equations, BFS to find value of equation
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
  static std::vector<double> calcEquation(
      std::vector<std::vector<std::string>>& equations,
      std::vector<double>& values,
      std::vector<std::vector<std::string>>& queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        adjacency_list;
    for (std::size_t i = 0; i < equations.size(); ++i) {
      adjacency_list[equations[i][0]][equations[i][1]] = values[i];
      adjacency_list[equations[i][1]][equations[i][0]] = 1.0 / values[i];
    }
    std::vector<double> query_answers(queries.size(), -1.0);
    for (std::size_t i = 0; i < queries.size(); ++i) {
      if (adjacency_list.contains(queries[i][0]) &&
          adjacency_list.contains(queries[i][1])) {
        if (queries[i][0] != queries[i][1]) {
          BFS(adjacency_list, queries[i], query_answers[i]);
        } else {
          query_answers[i] = 1.0;
        }
      }
    }
    return query_answers;
  }

private:
  static void BFS(
      const std::unordered_map<
          std::string, std::unordered_map<std::string, double>>& adjacency_list,
      const std::vector<std::string>& query, double& answer) {
    bool is_answer_set = false;
    std::queue<std::pair<std::string, double>> unvisited_nodes;
    std::unordered_set<std::string> visited_nodes;
    unvisited_nodes.push({query[0], 1.0});
    while (!is_answer_set && !unvisited_nodes.empty()) {
      std::pair<std::string, double> new_node =
          std::move(unvisited_nodes.front());
      unvisited_nodes.pop();
      visited_nodes.insert(new_node.first);
      for (auto b_iter = adjacency_list.find(new_node.first)->second.begin(),
                e_iter = adjacency_list.find(new_node.first)->second.end();
           b_iter != e_iter; ++b_iter) {
        if (visited_nodes.contains(b_iter->first)) {
          continue;
        }
        if (b_iter->first == query[1]) {
          answer = new_node.second * b_iter->second;
          is_answer_set = true;
          break;
        }
        unvisited_nodes.push({b_iter->first, new_node.second * b_iter->second});
      }
    }
  }
};

int main() {
  std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"c", "d"}};
  std::vector<double> values = {1.0, 1.0};
  std::vector<std::vector<std::string>> queries = {
      {"a", "c"}, {"b", "d"}, {"b", "a"}, {"d", "c"}};
  std::vector<double> query_answers =
      Solution::calcEquation(equations, values, queries);
  for (const auto& value : query_answers) {
    std::cout << value << ' ';
  }
  return 0;
}
