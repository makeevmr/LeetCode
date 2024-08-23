/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You
are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take
course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Time complexity: O(V + E)
Additional memory complexity: O(E)
Idea: use DFS algorithm to find cycle in graph
*/

#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    static bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> adjacency_list;
        fillGraph(adjacency_list, prerequisites);
        std::vector<int> visited_nodes(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (visited_nodes[i] == 0) {
                if (findCycleDFS(adjacency_list, visited_nodes, i)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    static void fillGraph(std::unordered_map<int, std::unordered_set<int>> &adjacency_list,
                          const std::vector<std::vector<int>> &prerequisites) {
        for (std::size_t i = 0; i < prerequisites.size(); ++i) {
            adjacency_list[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
    }

    // check if there are cycles in the directed graph
    static bool findCycleDFS(const std::unordered_map<int, std::unordered_set<int>> &adjacency_list,
                             std::vector<int> &visited_nodes, int curr_node) {
        visited_nodes[curr_node] = 1;
        if (auto f_iter = adjacency_list.find(curr_node); f_iter != adjacency_list.end()) {
            for (const auto &dependent_node : f_iter->second) {
                if (visited_nodes[dependent_node] == 1) {
                    return true;
                }
                if (visited_nodes[dependent_node] == 0) {
                    if (findCycleDFS(adjacency_list, visited_nodes, dependent_node)) {
                        return true;
                    }
                }
            }
        }
        visited_nodes[curr_node] = 2;
        return false;
    }
};
