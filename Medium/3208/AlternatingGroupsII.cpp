#include <iostream>
#include <vector>

class Solution {
public:
    static int numberOfAlternatingGroups(const std::vector<int> &colors, int k) {
        int start_ind = 0;
        int colors_size = colors.size();
        int counter = 0;
        while (start_ind < colors_size) {
            std::pair<bool, int> res = makeAlternating(colors, start_ind, k);
            if (res.first) {
                int prev = colors[(start_ind + k - 1) % colors_size];
                ++start_ind;
                ++counter;
                while (start_ind < colors_size) {
                    if (colors[(start_ind + k - 1) % colors_size] != prev) {
                        prev = colors[(start_ind + k - 1) % colors_size];
                        ++start_ind;
                        ++counter;
                    } else {
                        break;
                    }
                }
            } else {
                if (start_ind >= res.second) {
                    return counter;
                }
                start_ind = res.second;
            }
        }
        return counter;
    }

private:
    static std::pair<bool, int> makeAlternating(const std::vector<int> &colors, int start, int k) {
        int colors_size = static_cast<int>(colors.size());
        int seq_len = 1;
        int prev = start;
        int curr = (start + 1) % colors_size;
        while (seq_len < k) {
            if (colors[prev] != colors[curr]) {
                ++seq_len;
                prev = curr;
                curr = (curr + 1) % colors_size;
            } else {
                return {false, curr};
            }
        }
        return {true, -1};
    }
};

int main() {
    // std::vector<int> colors = {0, 1, 0, 1, 0};
    // int k = 3;
    // std::vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    // int k = 6;
    std::vector<int> colors = {1, 1, 0, 1};
    int k = 4;
    std::cout << Solution::numberOfAlternatingGroups(colors, k) << '\n';
    return 0;
}