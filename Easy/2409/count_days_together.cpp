#include <string>
#include <array>

static constexpr std::size_t kMonth = 12ULL;

template <std::size_t N>
static consteval std::array<int, N> calcDaysBeforeMonth(
    const std::array<int, N>& days_in_month) noexcept {
  std::array<int, N> days_before_month = {};
  for (std::size_t i = 1; i < N; ++i) {
    days_before_month[i] = days_before_month[i - 1] + days_in_month[i - 1];
  }
  return days_before_month;
}

static constexpr std::array<int, kMonth> kDaysInMonth = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static constexpr std::array<int, kMonth> kDaysBeforeMonth =
    calcDaysBeforeMonth(kDaysInMonth);

class Solution {
public:
  [[nodiscard]] static int countDaysTogether(const std::string& arrive_alice,
                                             const std::string& leave_alice,
                                             const std::string& arrive_bob,
                                             const std::string& leave_bob) {
    const int arrive_alice_int = convertDateToDays(arrive_alice);
    const int leave_alice_int = convertDateToDays(leave_alice);
    const int arrive_bob_int = convertDateToDays(arrive_bob);
    const int leave_bob_int = convertDateToDays(leave_bob);
    if (arrive_alice_int <= arrive_bob_int &&
        arrive_bob_int <= leave_alice_int) {
      return std::min(leave_alice_int, leave_bob_int) - arrive_bob_int + 1;
    }
    if (arrive_bob_int <= arrive_alice_int &&
        arrive_alice_int <= leave_bob_int) {
      return std::min(leave_alice_int, leave_bob_int) - arrive_alice_int + 1;
    }
    return 0;
  }

private:
  static int convertDateToDays(const std::string& date) {
    int total_days = kDaysBeforeMonth[std::stoi(date.substr(0, 2)) - 1];
    total_days += std::stoi(date.substr(3));
    return total_days;
  }
};

#include <iostream>

int main() {
  std::string arrive_alice = "08-15";
  std::string leave_alice = "08-18";
  std::string arrive_bob = "08-16";
  std::string leave_bob = "08-19";
  // std::string arrive_alice = "10-01";
  // std::string leave_alice = "10-31";
  // std::string arrive_bob = "11-01";
  // std::string leave_bob = "12-31";
  std::cout << Solution::countDaysTogether(arrive_alice, leave_alice,
                                           arrive_bob, leave_bob)
            << '\n';
  return 0;
}