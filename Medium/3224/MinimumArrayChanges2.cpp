/* You are given an integer array nums of size n where n is even, and an integer k.

You can perform some changes on the array, where in one change you can replace any element in the
array with any integer in the range from 0 to k.

You need to perform some changes (possibly none) such that the final array satisfies the following
condition:

There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).
Return the minimum number of changes required to satisfy the above condition. */

#include <bits/stdc++.h>
using ull = unsigned long long int;
using ll = long long int;

using namespace std;

class Solution {
public:
    static int minChanges(const vector<int> &nums, int k) {
        int curr_ind = 0;
        int nums_size = static_cast<int>(nums.size());
        unordered_map<int, int> abs_freq;
        map<int, int> max_diff_map;
        while (curr_ind < (nums_size / 2)) {
            const int &n1 = nums[curr_ind];
            const int &n2 = nums[nums_size - curr_ind - 1];
            int max_diff = max(max(n1, n2), k - min(n1, n2));
            ++abs_freq[abs(n1 - n2)];
            ++max_diff_map[max_diff];
            ++curr_ind;
        }
        vector<pair<int, int>> pref_sums_max_diff;
        for (auto &item : max_diff_map) {
            if (pref_sums_max_diff.empty()) {
                pref_sums_max_diff.push_back(std::move(item));
            } else {
                pref_sums_max_diff.push_back(
                    pair<int, int>{item.first, item.second + pref_sums_max_diff.back().second});
            }
        }
        vector<pair<int, int>> sorted_abs_freq;
        for (const auto &item : abs_freq) {
            sorted_abs_freq.push_back(std::pair<int, int>{item.second, item.first});
        }
        std::sort(sorted_abs_freq.begin(), sorted_abs_freq.end(),
                  std::greater<std::pair<int, int>>());
        int min_answer = numeric_limits<int>::max();
        for (const auto &item : sorted_abs_freq) {
            if (min_answer <= (nums_size / 2 - item.first)) {
                break;
            }
            int left = 0;
            int right = static_cast<int>(pref_sums_max_diff.size() - 1);
            auto f_iter = lower_bound(
                pref_sums_max_diff.begin(), pref_sums_max_diff.end(), item.second,
                [](const pair<int, int> &left, int right) { return left.first < right; });
            ll less_max_diff = 0;
            if (f_iter != pref_sums_max_diff.begin()) {
                less_max_diff = prev(f_iter)->second;
            }
            ull new_min_answer =
                less_max_diff * 2 + static_cast<ll>(nums_size / 2 - less_max_diff) - item.first;
            if (min_answer > new_min_answer) {
                min_answer = new_min_answer;
            }
        }
        return min_answer;
    }
};

int main() {
    std::vector<int> nums = {1, 0, 1, 2, 4, 3};
    int k = 4;
    // std::vector<int> nums = {0, 1, 2, 3, 3, 6, 5, 4};
    // int k = 6;
    cout << Solution::minChanges(nums, k) << '\n';
    return 0;
}
