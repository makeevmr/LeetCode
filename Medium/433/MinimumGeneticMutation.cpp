/* A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G',
and 'T'.
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene
where one mutation is defined as one single character changed in the gene string.
For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to
make it a valid gene string.
Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number
of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
Time complexity: O((bank_size ^ 2) * gen_size)
Additional memory complexity: O(bank_size * gen_size)
Idea: use BFS to find min_path in graph
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    static int minMutation(const std::string &startGene, const std::string &endGene,
                           const std::vector<std::string> &bank) {
        std::queue<std::string> queue;
        std::unordered_set<std::string> visited_nodes;
        queue.push(startGene);
        int mutations = 0;
        while (!queue.empty()) {
            std::size_t queue_size = queue.size();
            for (std::size_t i = 0; i < queue_size; ++i) {
                std::string curr_gen = std::move(queue.front());
                queue.pop();
                if (curr_gen == endGene) {
                    return mutations;
                }
                for (const auto &new_gen : bank) {
                    if (!visited_nodes.contains(new_gen) && isMutateable(curr_gen, new_gen)) {
                        queue.push(new_gen);
                    }
                }
                visited_nodes.insert(std::move(curr_gen));
            }
            ++mutations;
        }
        return -1;
    }

private:
    static bool isMutateable(const std::string &from_gen, const std::string &to_gen) {
        int diff = 0;
        for (std::size_t i = 0; i < from_gen.size(); ++i) {
            if (from_gen[i] != to_gen[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};

int main() {
    // std::string startGene = "AACCGGTT";
    // std::string endGene = "AACCGGTA";
    // std::vector<std::string> bank = {"AACCGGTA"};
    std::string startGene = "AACCGGTT";
    std::string endGene = "AAACGGTA";
    std::vector<std::string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    std::cout << Solution::minMutation(startGene, endGene, bank) << '\n';
    return 0;
}
