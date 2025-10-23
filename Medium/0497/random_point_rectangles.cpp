#include <vector>
#include <cstdint>
#include <map>
#include <random>

class Solution {
public:
  explicit Solution(const std::vector<std::vector<int>>& rects)
      : total_dots_(0),
        rects_(rects),
        dot_rect_map_() {
    for (std::size_t i = 0; i < rects.size(); ++i) {
      dot_rect_map_.insert(
          std::pair<std::uint64_t, std::size_t>{total_dots_ + 1, i});
      total_dots_ += getTotalRectDots(rects[i]);
    }
  }

  [[nodiscard]] std::vector<int> pick() const noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::uint64_t> distrib(1ULL, total_dots_);
    const auto uni_dist_num = distrib(gen);
    const auto f_iter = std::prev(dot_rect_map_.upper_bound(uni_dist_num));
    const std::vector<int>& picked_rect = rects_[f_iter->second];
    const auto picked_dot = uni_dist_num - f_iter->first + 1;
    const int x1 = picked_rect[0];
    const int y1 = picked_rect[1];
    const int x2 = picked_rect[2];
    const int rect_columns = x2 - x1 + 1;
    const int delta_rows = (picked_dot - 1) / rect_columns;
    const int delta_columns = picked_dot - delta_rows * rect_columns - 1;
    return {x1 + delta_columns, y1 + delta_rows};
  }

private:
  [[nodiscard]] std::uint64_t getTotalRectDots(
      const std::vector<int>& rect) const noexcept {
    return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
  }

  std::uint64_t total_dots_;
  const std::vector<std::vector<int>>& rects_;
  std::map<std::uint64_t, std::size_t> dot_rect_map_;
};