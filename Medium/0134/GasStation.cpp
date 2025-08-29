#include <iostream>
#include <vector>

class Solution {
public:
  static int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int gas_array_size = static_cast<int>(gas.size());
    int best_start_index = 0;
    int max_gas_amount = 0;
    int current_start_index = 0;
    int current_gas_amount = 0;
    int circular_gas = 0;
    for (int i = 0; i < gas_array_size; ++i) {
      if (current_gas_amount < 0) {
        current_gas_amount = 0;
        current_start_index = i;
      }
      circular_gas += gas[i] - cost[i];
      current_gas_amount += gas[i] - cost[i];
      if (current_gas_amount > max_gas_amount) {
        max_gas_amount = current_gas_amount;
        best_start_index = current_start_index;
      }
    }
    if (circular_gas < 0) {
      return -1;
    }
    int i = 0;
    while (current_gas_amount > 0) {
      current_gas_amount += gas[i] - cost[i];
      if (current_gas_amount > max_gas_amount) {
        best_start_index = current_start_index;
        break;
      }
      ++i;
    }
    return best_start_index;
  }
};

int main() {
  std::vector<int> gas = {1, 2, 3, 4, 5};
  std::vector<int> cost = {3, 4, 5, 1, 2};
  std::cout << Solution::canCompleteCircuit(gas, cost) << std::endl;
  return 0;
}
