#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet {
private:
  std::unordered_map<int, int> r_set_map;
  std::vector<int> r_set_array;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (r_set_map.find(val) != r_set_map.end()) {
      return false;
    }
    r_set_array.emplace_back(val);
    r_set_map.insert({val, r_set_array.size() - 1});
    return true;
  }

  bool remove(int val) {
    if (r_set_map.find(val) == r_set_map.end()) {
      return false;
    }
    int new_index = r_set_map[val];
    std::swap(r_set_array[new_index], r_set_array[r_set_array.size() - 1]);
    r_set_map[r_set_array[new_index]] = new_index;
    r_set_array.pop_back();
    r_set_map.erase(val);
    return true;
  }

  int getRandom() {
    return r_set_array[std::rand() % r_set_array.size()];
  }
};

int main() {
  RandomizedSet r_set;
  r_set.insert(1);
  r_set.insert(2);
  r_set.insert(3);
  r_set.insert(4);
  r_set.insert(5);
  r_set.insert(6);
  std::cout << r_set.getRandom() << std::endl;
  std::cout << r_set.getRandom() << std::endl;
  std::cout << r_set.getRandom() << std::endl;
  std::cout << r_set.getRandom() << std::endl;
  return 0;
}
