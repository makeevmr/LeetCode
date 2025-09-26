#include <string>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int numberOfRounds(const std::string& login_time,
                                          const std::string& logout_time) {
    int start_time_minutes = std::stoi(login_time.substr(0, 2)) * 60 +
                             std::stoi(login_time.substr(3));
    int end_time_minutes = std::stoi(logout_time.substr(0, 2)) * 60 +
                           std::stoi(logout_time.substr(3));
    if (start_time_minutes > end_time_minutes) {
      end_time_minutes += 24 * 60;
    }
    return std::max(0, end_time_minutes / 15 - (start_time_minutes + 14) / 15);
  }
};