/*
Given a string s and an integer k, return the length of the longest substring
of s such that the frequency of each character in this substring is greater than
or equal to k.

if no such substring exists, return 0.

Input: s = "aaabb", k = 3
Output: 3

Input: s = "ababbc", k = 2
Output: 5
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int longestSubstring(const string& s, int k) {
        const int alphabet_size = 26;
        unordered_set<char> unique_symbols(s.begin(), s.end());
        int total_unique_symbols = static_cast<int>(unique_symbols.size());
        const int s_size = static_cast<int>(s.size());
        int answer = 0;
        for (int max_unique_symbols = 1;
             max_unique_symbols <= total_unique_symbols; ++max_unique_symbols) {
            int left = -1;
            int right = -1;
            int unique_symbols = 0;
            int at_least_k_freq_symbols = 0;
            vector<int> symbol_freq(alphabet_size);
            while ((right + 1) < s_size) {
                const int ind = s[right + 1] - 'a';
                if ((symbol_freq[ind] == 0) &&
                    (unique_symbols == max_unique_symbols)) {
                    while (symbol_freq[s[left + 1] - 'a'] > 1) {
                        updateLeft(left, at_least_k_freq_symbols,
                                   unique_symbols, k, symbol_freq, s);
                    }
                    updateLeft(left, at_least_k_freq_symbols, unique_symbols, k,
                               symbol_freq, s);
                }
                ++right;
                ++symbol_freq[ind];
                if (symbol_freq[ind] == 1) {
                    ++unique_symbols;
                }
                if (symbol_freq[ind] == k) {
                    ++at_least_k_freq_symbols;
                }
                if (unique_symbols <= max_unique_symbols &&
                    unique_symbols == at_least_k_freq_symbols) {
                    answer = max(answer, right - left);
                }
            }
        }
        return answer;
    }

private:
    static void updateLeft(int& left, int& at_least_k_freq_symbols,
                           int& unique_symbols, const int& k,
                           vector<int>& symbol_freq, const string& s) {
        ++left;
        --symbol_freq[s[left] - 'a'];
        if (symbol_freq[s[left] - 'a'] == (k - 1)) {
            --at_least_k_freq_symbols;
        }
        if (symbol_freq[s[left] - 'a'] == 0) {
            --unique_symbols;
        }
    }
};

int main() {
    // string s = "aaabb";  // 3
    // int k = 3;
    // string s = "ababbc";  // 5
    // int k = 2;
    string s = "aaabbb";
    int k = 3;
    cout << Solution::longestSubstring(s, k) << '\n';
    return 0;
}
