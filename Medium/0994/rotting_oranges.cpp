#include <vector>
#include <queue>
#include <array>
#include <limits>

class Solution {
public:
  [[nodiscard]] static int orangesRotting(std::vector<std::vector<int>>& grid) {
    constexpr int kIntMax = std::numeric_limits<int>::max();
    const int& rows = static_cast<int>(grid.size());
    const int& columns = static_cast<int>(grid.front().size());
    std::vector<std::vector<std::pair<int, int>>> min_rotten_time(
        rows, std::vector<std::pair<int, int>>(columns, {0, kIntMax}));
    std::vector<std::pair<int, int>> rotten_coords;
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        min_rotten_time[row][column].first = grid[row][column];
        if (grid[row][column] == 2) {
          rotten_coords.emplace_back(row, column);
        }
      }
    }
    int step = 3;
    for (const auto& rotten_coord : rotten_coords) {
      bfs(min_rotten_time, rotten_coord.first, rotten_coord.second, rows,
          columns, step);
      ++step;
    }
    int max_time = 0;
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        const auto& [step, time] = min_rotten_time[row][column];
        if (step == 0) {
          continue;
        }
        if (step == 1) {
          return -1;
        }
        max_time = std::max(max_time, time);
      }
    }
    return max_time;
  }

private:
  static void bfs(
      std::vector<std::vector<std::pair<int, int>>>& min_rotten_time,
      const int& row, const int& column, const int& rows, const int& columns,
      const int& step) {
    int time = 0;
    min_rotten_time[row][column] = {step, time};
    std::queue<std::pair<int, int>> queue;
    queue.push({row, column});
    while (!queue.empty()) {
      ++time;
      size_t queue_size = queue.size();
      for (size_t _ = 0; _ < queue_size; ++_) {
        std::pair<int, int> curr_coord = queue.front();
        queue.pop();
        for (const auto& dir : kDirection) {
          std::pair<int, int> adj_coord{curr_coord.first + dir.first,
                                        curr_coord.second + dir.second};
          const auto& [adj_x, adj_y] = adj_coord;
          if ((0 <= adj_x) && (adj_x < rows) && (0 <= adj_y) &&
              (adj_y < columns) &&
              (min_rotten_time[adj_x][adj_y].first < step) &&
              (min_rotten_time[adj_x][adj_y].first != 0)) {
            auto& [curr_step, curr_time] = min_rotten_time[adj_x][adj_y];
            curr_step = step;
            curr_time = std::min(curr_time, time);
            queue.push(adj_coord);
          }
        }
      }
    }
  }

  static constexpr std::array<std::pair<int, int>, 4> kDirection = {
      std::pair<int, int>{-1, 0}, std::pair<int, int>{0, -1},
      std::pair<int, int>{1, 0}, std::pair<int, int>{0, 1}};
};