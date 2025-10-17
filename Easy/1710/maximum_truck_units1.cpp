#include <vector>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static int maximumUnits(
      std::vector<std::vector<int>>& box_types, int truck_size) {
    std::sort(box_types.begin(), box_types.end(),
              [](const std::vector<int>& box_type_left,
                 const std::vector<int>& box_type_right) {
                return box_type_left[1] > box_type_right[1];
              });
    int max_units = 0;
    std::size_t i = 0;
    const std::size_t box_types_size = box_types.size();
    while ((truck_size > 0) && (i < box_types_size)) {
      int num_of_boxes = std::min(truck_size, box_types[i][0]);
      max_units += num_of_boxes * box_types[i][1];
      truck_size -= num_of_boxes;
      ++i;
    }
    return max_units;
  }
};
