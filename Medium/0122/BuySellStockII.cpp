#include <iostream>
#include <vector>

class Solution {
public:
  static int maxProfit(const std::vector<int>& prices) {
    int overall_profit = 0;
    int current_stock_price = prices[0];
    size_t prices_size = prices.size();
    for (size_t i = 1; i < prices_size; ++i) {
      if ((prices[i] - current_stock_price) > 0) {
        overall_profit += prices[i] - current_stock_price;
      }
      current_stock_price = prices[i];
    }
    return overall_profit;
  }
};

int main() {
  std::vector<int> prices = {7, 6, 4, 3, 1};
  std::cout << Solution::maxProfit(prices) << std::endl;
  return 0;
}
