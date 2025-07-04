/* Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the
key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict
the least recently used key. The functions get and put must each run in O(1) average time
complexity.
Time complexity: get is O(1) on average, put is O(1) on averave
Additional memory complexity: O(capacity)
Idea: use unordered_map<int, Node *> to access key in O(1), Node is node of doubly linked list to
change last use of node in O(1)
*/

#include <iostream>
#include <unordered_map>

class LRUCache {
    class LRUList;

public:
    LRUCache(int capacity)
        : capacity(static_cast<std::size_t>(capacity)), lru_list(LRUList()),
          nodes_map(std::unordered_map<int, Node *>()) {}

    ~LRUCache() = default;

    [[nodiscard]] int get(int key) noexcept {
        if (!nodes_map.contains(key)) {
            return -1;
        }
        lru_list.advanceNode(nodes_map[key]);
        return nodes_map[key]->value;
    }

    void put(int key, int value) {
        if (nodes_map.contains(key)) {
            lru_list.advanceNode(nodes_map[key]);
            lru_list.updateValue(nodes_map[key], value);
        } else {
            if (capacity == nodes_map.size()) {
                nodes_map.erase(lru_list.deleteLRU());
            }
            nodes_map.insert({key, lru_list.pushBack(key, value)});
        }
    }

private:
    struct Node {
    public:
        Node(const int &key, const int &value)
            : key(key), value(value), left(nullptr), right(nullptr) {}

        ~Node() {
            left = nullptr;
            right = nullptr;
        }

        int key;
        int value;
        Node *left;
        Node *right;
    };

    class LRUList {
    public:
        LRUList() : head(nullptr), tail(nullptr) {}

        ~LRUList() {
            Node *curr_node = head;
            while (curr_node != nullptr) {
                Node *next_node = curr_node->right;
                delete curr_node;
                curr_node = next_node;
            }
            head = nullptr;
            tail = nullptr;
        }

        Node *pushBack(const int &key, const int &value) {
            Node *new_node = new Node(key, value);
            if (tail == nullptr) {
                head = new_node;
            } else {
                tail->right = new_node;
                new_node->left = tail;
            }
            tail = new_node;
            return tail;
        }

        void advanceNode(Node *const node_to_advance) noexcept {
            if (tail == node_to_advance) {
                return;
            }
            node_to_advance->right->left = node_to_advance->left;
            if (node_to_advance == head) {
                head = node_to_advance->right;
            } else {
                node_to_advance->left->right = node_to_advance->right;
            }
            tail->right = node_to_advance;
            node_to_advance->left = tail;
            node_to_advance->right = nullptr;
            tail = node_to_advance;
        }

        void updateValue(Node *const node_to_update, const int &new_value) noexcept {
            node_to_update->value = new_value;
        }

        [[nodiscard]] int deleteLRU() noexcept {
            Node *node_to_delete = head;
            head = head->right;
            if (tail == node_to_delete) {
                tail = nullptr;
            }
            int deleted_key = node_to_delete->key;
            delete node_to_delete;
            return deleted_key;
        }

    private:
        Node *head;
        Node *tail;
    };

    std::size_t capacity;
    LRUList lru_list;
    std::unordered_map<int, Node *> nodes_map;
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << '\n';
    cache.put(3, 3);
    std::cout << cache.get(2) << '\n';
    cache.put(4, 4);
    std::cout << cache.get(1) << '\n';
    std::cout << cache.get(3) << '\n';
    std::cout << cache.get(4) << '\n';
    return 0;
}
