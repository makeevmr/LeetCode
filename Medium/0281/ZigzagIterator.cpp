/* Given two vectors of integers v1 and v2, implement an iterator to return
their elements alternately.

Implement the ZigzagIterator class:

ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two
vectors v1 and v2. boolean hasNext() returns true if the iterator still has
elements, and false otherwise. int next() returns the current element of the
iterator and moves the iterator to the next element. Time complexity: O(v1_size
+ v2_size) Additional memory complexity: O(1) Idea: use two pointers to store
current positions of vectors
*/

#include <iostream>
#include <vector>

class ZigzagIterator {
public:
  ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2)
      : is_v1_bigger_(v1.size() > v2.size()),
        v1_ind_(0),
        v2_ind_(0),
        v1_(v1),
        v2_(v2) {}

  [[nodiscard]] int next() {
    if (hasNext()) {
      if (v1_ind_ == v1_.size()) {
        return v2_[v2_ind_++];
      }
      if (v2_ind_ == v2_.size()) {
        return v1_[v1_ind_++];
      }
      if (v1_ind_ == v2_ind_) {
        return v1_[v1_ind_++];
      }
      return v2_[v2_ind_++];
    }
    return -1;
  }

  [[nodiscard]] bool hasNext() const noexcept {
    return is_v1_bigger_ ? v1_ind_ < v1_.size() : v2_ind_ < v2_.size();
  }

private:
  bool is_v1_bigger_;
  std::size_t v1_ind_;
  std::size_t v2_ind_;
  const std::vector<int>& v1_;
  const std::vector<int>& v2_;
};

int main() {
  std::vector<int> v1 = {1, 2};
  std::vector<int> v2 = {3, 4, 5, 6};
  // std::vector<int> v1 = {1};
  // std::vector<int> v2 = {};
  // std::vector<int> v1 = {};
  // std::vector<int> v2 = {};
  ZigzagIterator z_iter(v1, v2);
  while (z_iter.hasNext()) {
    std::cout << z_iter.next() << ' ';
  }
  std::cout << '\n';
  return 0;
}
