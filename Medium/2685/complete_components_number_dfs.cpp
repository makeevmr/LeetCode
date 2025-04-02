/*
You are given an integer n. There is an undirected graph with n vertices,
numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i]
= [ai, bi] denotes that there exists an undirected edge connecting vertices ai
and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path
between any two vertices, and no vertex of the subgraph shares an edge with a
vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between
every pair of its vertices.
Time complexity: O(E + V)
Additional memory complexity: O(E + V)
Idea: iterate through all vertices, if vertex is unvisited launch dfs(vertex)
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    [[nodiscard]] static int countCompleteComponents(
        int n, const std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adj_list;
        fillAdjList(adj_list, edges);
        int total_components = 0;
        int complete_components = 0;
        std::vector<int> component(n, 0);
        for (int i = 0; i < n; ++i) {
            if (component[i] == 0) {
                ++total_components;
                if (isCompleteComponent(adj_list, component, total_components,
                                        i)) {
                    ++complete_components;
                }
            }
        }
        return complete_components;
    }

private:
    static void fillAdjList(std::unordered_map<int, std::vector<int>>& adj_list,
                            const std::vector<std::vector<int>>& edges) {
        for (const auto& item : edges) {
            adj_list[item[0]].push_back(item[1]);
            adj_list[item[1]].push_back(item[0]);
        }
    }

    // dfs returns number of incident edges of vertex_ind
    [[nodiscard]] static std::size_t dfs(
        const std::unordered_map<int, std::vector<int>>& adj_list,
        std::vector<int>& component, const int& total_components,
        const int& vertex_ind, bool& is_equal_edges_num,
        std::size_t& vertex_num_in_comp) {
        component[vertex_ind] = total_components;
        ++vertex_num_in_comp;
        if (const auto &f_iter = adj_list.find(vertex_ind),
            e_iter = adj_list.end();
            f_iter != e_iter) {
            for (const int& adj_vertex : f_iter->second) {
                if (component[adj_vertex] == 0) {
                    is_equal_edges_num &=
                        (f_iter->second.size() ==
                         dfs(adj_list, component, total_components, adj_vertex,
                             is_equal_edges_num, vertex_num_in_comp));
                }
            }
            return f_iter->second.size();
        }
        return 0;
    }

    [[nodiscard]] static bool isCompleteComponent(
        const std::unordered_map<int, std::vector<int>>& adj_list,
        std::vector<int>& component, const int& total_components,
        const int& vertex_ind) {
        bool is_equal_edges_num = true;
        std::size_t vertex_num_in_comp = 0;
        std::size_t edges =
            dfs(adj_list, component, total_components, vertex_ind,
                is_equal_edges_num, vertex_num_in_comp);
        return is_equal_edges_num && ((edges + 1) == vertex_num_in_comp);
    }
};