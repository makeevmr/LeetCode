#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int minimumCost(const std::string& target,
                                       const std::vector<std::string>& words,
                                       const std::vector<int>& costs) {
    AhoCorasickAutomata<'a', 'z'> automata;
    const int words_size = words.size();
    for (int i = 0; i < words_size; ++i) {
      automata.addString(words[i], costs[i], i);
    }
    automata.buildAutomata();
    return automata.findMinCost(target, words);
  }

private:
  template <char kAlphaLeft, char kAlphaRight>
    requires(kAlphaRight >= kAlphaLeft)
  class AhoCorasickAutomata {
  public:
    AhoCorasickAutomata()
        : nodes_(std::vector<Node>(1)) {}

    void addString(const std::string& s, int cost, int word_ind) {
      int curr_node = 0;
      for (const char& symbol : s) {
        const int symbol_ind = symbol - kAlphaLeft;
        if (nodes_[curr_node].next_[symbol_ind] == kUndefinedFlag) {
          nodes_[curr_node].next_[symbol_ind] = static_cast<int>(nodes_.size());
          nodes_.emplace_back();
        }
        curr_node = nodes_[curr_node].next_[symbol_ind];
      }
      nodes_[curr_node].cost_ = std::min(nodes_[curr_node].cost_, cost);
      nodes_[curr_node].word_ind_ = word_ind;
    }

    // Aho-Corasick algorithm implementation
    // See: https://www.youtube.com/watch?v=V7S80KpbQpk&list=LL&index=5&t=2s
    void buildAutomata() {
      nodes_[0].suffix_link_ = kNoPathFlag;
      nodes_[0].to_terminal_link_ = kNoPathFlag;
      for (char c = kAlphaLeft; c <= kAlphaRight; ++c) {
        if (nodes_[0].next_[c - kAlphaLeft] == kUndefinedFlag) {
          nodes_[0].next_[c - kAlphaLeft] = 0;
        }
      }
      std::queue<int> nodes_queue;
      nodes_queue.push(0);
      while (!nodes_queue.empty()) {
        int parent = nodes_queue.front();
        nodes_queue.pop();
        for (char c = kAlphaLeft; c <= kAlphaRight; ++c) {
          int child = nodes_[parent].next_[c - kAlphaLeft];
          if (nodes_[child].suffix_link_ != kUndefinedFlag) {
            continue;
          }
          nodes_[child].suffix_link_ =
              (parent == 0
                   ? 0
                   : nodes_[nodes_[parent].suffix_link_].next_[c - kAlphaLeft]);
          const int& suff_link_node = nodes_[child].suffix_link_;
          nodes_[child].to_terminal_link_ =
              (nodes_[suff_link_node].cost_ == kMaxCost
                   ? nodes_[suff_link_node].to_terminal_link_
                   : suff_link_node);
          for (char d = kAlphaLeft; d <= kAlphaRight; ++d) {
            if (nodes_[child].next_[d - kAlphaLeft] != kUndefinedFlag) {
              continue;
            }
            nodes_[child].next_[d - kAlphaLeft] =
                nodes_[suff_link_node].next_[d - kAlphaLeft];
          }
          nodes_queue.push(child);
        }
      }
    }

    int findMinCost(const std::string& target,
                    const std::vector<std::string>& words) {
      int curr_node = 0;
      std::vector<int> min_costs(target.size(), kMaxCost);
      for (std::size_t i = 0; i < target.size(); ++i) {
        curr_node = nodes_[curr_node].next_[target[i] - kAlphaLeft];
        int traverse_back_node = curr_node;
        do {
          if (nodes_[traverse_back_node].cost_ != kMaxCost) {
            std::size_t word_size =
                words[nodes_[traverse_back_node].word_ind_].size();
            if (i >= word_size) {
              if (min_costs[i - word_size] != kMaxCost) {
                min_costs[i] = std::min(min_costs[i],
                                        min_costs[i - word_size] +
                                            nodes_[traverse_back_node].cost_);
              }
            } else {
              min_costs[i] =
                  std::min(min_costs[i], nodes_[traverse_back_node].cost_);
            }
          }
          traverse_back_node = nodes_[traverse_back_node].to_terminal_link_;
        } while (traverse_back_node != kNoPathFlag);
      }
      return min_costs.back() == kMaxCost ? kUndefinedFlag : min_costs.back();
    }

  private:
    static constexpr int kAlphaSize =
        static_cast<int>(kAlphaRight - kAlphaLeft) + 1;
    static constexpr int kMaxCost = std::numeric_limits<int>::max();

    static constexpr int kUndefinedFlag = -1;
    static constexpr int kNoPathFlag = -2;

    struct Node {
      int cost_;
      int word_ind_;
      int suffix_link_;
      int to_terminal_link_;
      int next_[kAlphaRight - kAlphaLeft + 1];

      Node()
          : cost_(kMaxCost),
            word_ind_(kUndefinedFlag),
            suffix_link_(kUndefinedFlag),
            to_terminal_link_(kUndefinedFlag) {
        memset(next_, kUndefinedFlag, sizeof next_);
      }
    };

    std::vector<Node> nodes_;
  };
};
