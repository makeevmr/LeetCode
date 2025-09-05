#include <vector>
#include <stack>

class Solution {
public:
  [[nodiscard]] static int largestRectangleArea(
      const std::vector<int>& heights) {
    int max_rect_area = 0;
    int heights_size = static_cast<int>(heights.size());
    std::stack<int> gist_stack;
    gist_stack.push(-1);
    for (int i = 0; i < heights_size; ++i) {
      if ((gist_stack.top() != -1) &&
          (heights[gist_stack.top()] > heights[i])) {
        while ((gist_stack.top() != -1) &&
               (heights[gist_stack.top()] >= heights[i])) {
          int height = heights[gist_stack.top()];
          gist_stack.pop();
          max_rect_area =
              std::max(max_rect_area, height * (i - gist_stack.top() - 1));
        }
      }
      gist_stack.push(i);
    }
    while (gist_stack.top() != -1) {
      int height = heights[gist_stack.top()];
      gist_stack.pop();
      max_rect_area = std::max(max_rect_area,
                               height * (heights_size - gist_stack.top() - 1));
    }
    return max_rect_area;
  }
};