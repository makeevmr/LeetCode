#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  static void dfs(const vector<unordered_set<int>>& adj_list,
                  vector<bool>& visited, vector<int>& merged_groups,
                  int acc_id) {
    visited[acc_id] = true;
    merged_groups.push_back(acc_id);
    for (const int& new_group_id : adj_list[acc_id]) {
      if (!visited[new_group_id]) {
        dfs(adj_list, visited, merged_groups, new_group_id);
      }
    }
  }

public:
  static vector<vector<string>> accountsMerge(
      const vector<vector<string>>& accounts) {
    unordered_map<string, unordered_set<int>> email_acc_map;
    int accounts_size = static_cast<int>(accounts.size());
    for (int acc_id = 0; acc_id < accounts_size; ++acc_id) {
      for (auto b_iter = next(accounts[acc_id].begin());
           b_iter != accounts[acc_id].end(); ++b_iter) {
        email_acc_map[*b_iter].insert(acc_id);
      }
    }
    vector<unordered_set<int>> adj_list(accounts_size);
    for (const auto& [_, groups] : email_acc_map) {
      int prev = *groups.begin();
      for (auto iter = next(groups.begin()); iter != groups.end(); ++iter) {
        int curr = *iter;
        adj_list[prev].insert(curr);
        prev = curr;
      }
      if (groups.size() > 1) {
        adj_list[prev].insert(*groups.begin());
      }
    }
    vector<pair<int, unordered_set<string>>> merged_accounts;
    vector<bool> visited(accounts_size, false);
    vector<int> merged_groups;
    for (int acc_id = 0; acc_id < accounts_size; ++acc_id) {
      if (!visited[acc_id]) {
        dfs(adj_list, visited, merged_groups, acc_id);
        merged_accounts.push_back({acc_id, unordered_set<string>()});
        auto& new_merged_acc = merged_accounts.back().second;
        for (const int& group : merged_groups) {
          for (size_t i = 1; i < accounts[group].size(); ++i) {
            new_merged_acc.insert(accounts[group][i]);
          }
        }
        merged_groups.clear();
      }
    }
    vector<vector<string>> answer;
    for (const auto& [acc_id, emails_set] : merged_accounts) {
      answer.push_back(vector<string>{accounts[acc_id].front()});
      auto& new_acc = answer.back();
      for (const string& email : emails_set) {
        new_acc.push_back(email);
      }
      sort(next(new_acc.begin()), new_acc.end());
    }
    return answer;
  }
};

int main() {
  // vector<vector<string>> accounts = {
  //     {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
  //     {"John", "johnsmith@mail.com", "john00@mail.com"},
  //     {"Mary", "mary@mail.com"},
  //     {"John", "johnnybravo@mail.com"}};
  vector<vector<string>> accounts = {
      {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
       {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
       {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
       {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
       {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}}};
  auto ans = Solution::accountsMerge(accounts);
  for (const auto& acc : ans) {
    for (const auto& str : acc) {
      cout << str << ' ';
    }
    cout << '\n';
  }
  return 0;
}
