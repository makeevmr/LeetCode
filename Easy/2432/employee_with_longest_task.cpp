#include <vector>

class Solution {
public:
  [[nodiscard]] static int hardestWorker(
      [[maybe_unused]] int n, const std::vector<std::vector<int>>& logs) {
    int curr_time = 0;
    int max_work_time = -1;
    int worker_id = -1;
    for (const auto& log : logs) {
      int new_work_time = log[1] - curr_time;
      if (max_work_time < new_work_time) {
        max_work_time = new_work_time;
        worker_id = log[0];
      } else if (max_work_time == new_work_time && log[0] < worker_id) {
        worker_id = log[0];
      }
      curr_time = log[1];
    }
    return worker_id;
  }
};