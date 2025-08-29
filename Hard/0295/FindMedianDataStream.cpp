/* The median is the middle value in an ordered integer list. If the size of the
list is even, there is no middle value, and the median is the mean of the two
middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data
structure. double findMedian() returns the median of all elements so far.
Answers within 10-5 of the actual answer will be accepted. Time complexity:
addNum(O(log(n))), findMedian(O(1)) Additional memory complexity: O(n) Idea: use
two heaps: left_max_heap_ and right_min_heap_ too keep track of elements that is
smaller and greater than median
*/

#include <iostream>
#include <array>
#include <queue>
#include <vector>

class MedianFinder {
public:
  MedianFinder()
      : is_empty_finder_(true),
        is_median_exist_(false),
        median_(),
        left_max_heap_(),
        right_min_heap_() {}

  void addNum(int num) {
    if (is_median_exist_) {
      if (median_[0] <= num) {
        right_min_heap_.push(num);
        median_[1] = right_min_heap_.top();
        right_min_heap_.pop();
      } else {
        left_max_heap_.push(num);
        median_[1] = median_[0];
        median_[0] = left_max_heap_.top();
        left_max_heap_.pop();
      }
    } else {
      if (is_empty_finder_) {
        is_empty_finder_ = false;
        median_[0] = num;
      } else {
        if (num < median_[0]) {
          left_max_heap_.push(num);
          right_min_heap_.push(median_[1]);
        } else if (num <= median_[1]) {
          left_max_heap_.push(median_[0]);
          right_min_heap_.push(median_[1]);
          median_[0] = num;
        } else {
          left_max_heap_.push(median_[0]);
          right_min_heap_.push(num);
          median_[0] = median_[1];
        }
      }
    }
    is_median_exist_ = !is_median_exist_;
  }

  double findMedian() {
    if (is_median_exist_) {
      return static_cast<double>(median_[0]);
    }
    return static_cast<double>(median_[0] + median_[1]) / 2.0;
  }

private:
  bool is_empty_finder_;
  bool is_median_exist_;
  std::array<int, 2> median_;
  std::priority_queue<int> left_max_heap_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right_min_heap_;
};

int main() {
  MedianFinder finder;
  finder.addNum(1);
  finder.addNum(2);
  std::cout << finder.findMedian() << '\n';
  finder.addNum(3);
  std::cout << finder.findMedian() << '\n';
  return 0;
}