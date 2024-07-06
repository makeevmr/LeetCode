#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
    static long long maximumPoints(std::vector<int> &enemyEnergies, int currentEnergy) {
        long long currentEnergy_ll = static_cast<long long>(currentEnergy);
        long long max_points = 0;
        long long min_energy = std::numeric_limits<long long>::max();
        int min_index = -1;
        for (std::size_t i = 0; i < enemyEnergies.size(); ++i) {
            if (enemyEnergies[i] < min_energy) {
                min_energy = enemyEnergies[i];
                min_index = static_cast<int>(i);
            }
        }
        if (min_energy > currentEnergy) {
            return max_points;
        }
        currentEnergy_ll -= min_energy;
        ++max_points;
        for (std::size_t i = 0; i < enemyEnergies.size(); ++i) {
            if (min_index != static_cast<int>(i)) {
                currentEnergy_ll += enemyEnergies[i];
            }
        }
        max_points += currentEnergy_ll / enemyEnergies[min_index];
        return max_points;
    }
};

int main() {
    // std::vector<int> enemyEnergies = {3, 2, 2};
    // int currentEnergy = 2;
    std::vector<int> enemyEnergies = {2};
    int currentEnergy = 10;
    std::cout << Solution::maximumPoints(enemyEnergies, currentEnergy) << '\n';
    return 0;
}
