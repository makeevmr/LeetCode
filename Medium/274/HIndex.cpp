#include <iostream>
#include <vector>

class Solution {
public:
    static int hIndex(const std::vector<int> &citations) {
        const int max_citations = 1001;
        int h_index_array[max_citations];
        for (int i = 0; i < max_citations; ++i) {
            h_index_array[i] = 0;
        }
        for (int citation : citations) {
            ++h_index_array[citation];
        }
        int h_index = 0;
        int current_papers = 0;
        for (int i = max_citations - 1; i >= 0; --i) {
            current_papers += h_index_array[i];
            if (current_papers >= i) {
                h_index = i;
                break;
            }
        }
        return h_index;
    }
};

int main() {
    std::vector<int> citations = {3, 0, 6, 1, 5};
    std::cout << Solution::hIndex(citations) << std::endl;
    return 0;
}
