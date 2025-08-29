/* Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

#include <cstddef>
#include <new>
#include <stdexcept>
#include <utility>

class MinStack {
public:
  using reference = int&;
  using const_reference = const int&;
  using size_type = std::size_t;

  MinStack()
      : data(reinterpret_cast<std::pair<int, int>*>(
            ::operator new(sizeof(std::pair<int, int>) * 100))),
        size(0),
        capacity(100) {}

  ~MinStack() {
    ::operator delete(data);
  }

  // Modifiers
  void resize(size_type new_capacity) {
    std::pair<int, int>* new_data = reinterpret_cast<std::pair<int, int>*>(
        ::operator new(sizeof(std::pair<int, int>) * new_capacity));
    size_type copied_objects = 0;
    while (copied_objects < size) {
      new (new_data + copied_objects)
          std::pair<int, int>(std::move(data[copied_objects]));
      ++copied_objects;
    }
    ::operator delete(data);
    data = new_data;
    capacity = new_capacity;
  }

  void push(int val) {
    if (size == capacity) {
      resize(2 * capacity);
    }
    int new_min = val;
    if (size != 0) {
      new_min = val < data[size - 1].second ? val : data[size - 1].second;
    }
    new (data + size) std::pair<int, int>({val, new_min});
    ++size;
  }

  void pop() {
    if (size == 0) {
      throw std::length_error("Empty stack");
    }
    --size;
  }

  // Element access
  [[nodiscard]] reference top() {
    if (size == 0) {
      throw std::length_error("Empty stack");
    }
    return data[size - 1].first;
  }

  [[nodiscard]] const_reference top() const {
    if (size == 0) {
      throw std::length_error("Empty stack");
    }
    return data[size - 1].first;
  }

  [[nodiscard]] int getMin() {
    if (size == 0) {
      throw std::length_error("Empty stack");
    }
    return data[size - 1].second;
  }

private:
  std::pair<int, int>* data;
  size_type size;
  size_type capacity;
};
