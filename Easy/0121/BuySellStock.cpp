#include <iostream>
#include <vector>

class Solution {
public:
    static int maxProfit(const std::vector<int> &prices) {
        int current_profit = 0;
        int new_purchase_day = 0;
        size_t prices_size = prices.size();
        for (size_t i = 1; i < prices_size; ++i) {
            if ((prices[i] - prices[new_purchase_day]) > current_profit) {
                current_profit = prices[i] - prices[new_purchase_day];
            }
            if (prices[new_purchase_day] > prices[i]) {
                new_purchase_day = i;
            }
        }
        return current_profit;
    }
};

int main() {
    std::vector<int> prices = {7, 6, 4, 3, 1};
    std::cout << Solution::maxProfit(prices) << std::endl;
    return 0;
}
