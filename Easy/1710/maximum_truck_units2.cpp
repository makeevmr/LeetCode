#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
  [[nodiscard]] static int maximumUnits(
      const std::vector<std::vector<int>>& box_types, int truck_size) {
    auto lambda = [](const std::vector<int>& box_type_left,
                     const std::vector<int>& box_type_right) {
      return box_type_left[1] < box_type_right[1];
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        decltype(lambda)>
        max_heap(lambda);
    std::for_each(box_types.begin(), box_types.end(),
                  [&max_heap](const std::vector<int>& box_type) {
                    max_heap.push(box_type);
                  });
    int max_units = 0;
    while ((truck_size > 0) && (!max_heap.empty())) {
      const auto box_type = max_heap.top();
      max_heap.pop();
      int num_of_boxes = std::min(truck_size, box_type[0]);
      max_units += num_of_boxes * box_type[1];
      truck_size -= num_of_boxes;
    }
    return max_units;
  }
};