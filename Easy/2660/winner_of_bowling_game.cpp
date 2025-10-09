#include <vector>

class Solution {
public:
  [[nodiscard]] static int isWinner(const std::vector<int>& player1,
                                    const std::vector<int>& player2) {
    const int player1_score = getScore(player1);
    const int player2_score = getScore(player2);
    if (player1_score == player2_score) {
      return 0;
    }
    return player1_score > player2_score ? 1 : 2;
  }

private:
  [[nodiscard]] static int getScore(const std::vector<int>& player) {
    int total_score = 0;
    int prev_10_ind = -3;
    int turns = static_cast<int>(player.size());
    for (int i = 0; i < turns; ++i) {
      if (i - prev_10_ind <= 2) {
        total_score += 2 * player[i];
      } else {
        total_score += player[i];
      }
      if (player[i] == 10) {
        prev_10_ind = i;
      }
    }
    return total_score;
  }
};