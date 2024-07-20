/* You are given an integer array nums of size n where n is even, and an integer k.
You can perform some changes on the array, where in one change you can replace any element in the
array with any integer in the range from 0 to k.
You need to perform some changes (possibly none) such that the final array satisfies the following
condition:
There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).
Return the minimum number of changes required to satisfy the above condition.
*/

#include <bits/stdc++.h>
using ull = unsigned long long int;
using ll = long long int;

using namespace std;

class Solution {
public:
    static int minChanges(const vector<int> &nums, int k) {
        unordered_map<int, int> abs_freq;
        int nums_size = static_cast<int>(nums.size());
        int curr_ind = 0;
        while (curr_ind < nums_size / 2) {
            ++abs_freq[abs(nums[curr_ind] - nums[nums_size - curr_ind - 1])];
            ++curr_ind;
        }
        std::vector<std::pair<int, int>> sorted_freq;
        for (const auto &item : abs_freq) {
            sorted_freq.push_back(std::pair<int, int>{item.second, item.first});
        }
        std::sort(sorted_freq.begin(), sorted_freq.end(), std::greater<std::pair<int, int>>());
        int min_answer = std::numeric_limits<int>::max();
        for (const auto &pair : sorted_freq) {
            if (min_answer <= (nums_size / 2 - pair.first)) {
                break;
            }
            curr_ind = 0;
            int curr_answer = 0;
            while (curr_ind < nums_size / 2) {
                if (abs(nums[curr_ind] - nums[nums_size - curr_ind - 1]) != pair.second) {
                    if (isChangablePair(nums[curr_ind], nums[nums_size - curr_ind - 1], k,
                                        pair.second)) {
                        ++curr_answer;
                    } else {
                        curr_answer += 2;
                    }
                }
                ++curr_ind;
            }
            if (min_answer > curr_answer) {
                min_answer = curr_answer;
            }
        }
        return min_answer;
    }

private:
    static bool isChangablePair(int n1, int n2, int k, int x) {
        return (n1 + x <= k) || (n1 - x >= 0) || (n2 + x <= k) || (n2 - x >= 0);
    }
};

int main() {
    // std::vector<int> nums = {1, 0, 1, 2, 4, 3};
    // int k = 4;
    std::vector<int> nums = {0, 1, 2, 3, 3, 6, 5, 4};
    int k = 6;
    cout << Solution::minChanges(nums, k) << '\n';
    return 0;
}