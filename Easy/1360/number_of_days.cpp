#include <string>
#include <cstdint>
#include <array>
#include <cmath>

class Solution {
public:
  [[nodiscard]] static int daysBetweenDates(const std::string& date1,
                                            const std::string& date2) {
    std::int64_t days_dist = std::abs(dateToDays(date1) - dateToDays(date2));
    return static_cast<int>(days_dist);
  }

private:
  static std::int64_t dateToDays(const std::string& date) {
    const int year = std::stoi(date.substr(0, 4));
    const int month = std::stoi(date.substr(5, 2));
    const int day = std::stoi(date.substr(8));
    const int full_years = year - 1;
    std::int64_t total_days = full_years * 365;
    int leap_years = (full_years / 4) - (full_years / 100) + (full_years / 400);
    total_days += leap_years;
    for (int pass_month = 0; pass_month < month - 1; ++pass_month) {
      total_days += kDaysInMonth[pass_month];
      if (pass_month == 1 &&
          ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        total_days += 1;
      }
    }
    total_days += day;
    return total_days;
  }

private:
  static constexpr std::array<int, 12> kDaysInMonth = {31, 28, 31, 30, 31, 30,
                                                       31, 31, 30, 31, 30, 31};
};

#include <iostream>

int main() {
  std::string date1 = "2074-09-12";
  std::string date2 = "1983-01-08";
  std::cout << "Date 1: " << Solution::dateToDays(date1) << '\n';
  std::cout << "Date 2: " << Solution::dateToDays(date2) << '\n';
  std::cout << Solution::daysBetweenDates(date1, date2) << '\n';
  return 0;
}