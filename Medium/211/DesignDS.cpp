/* Design a data structure that supports adding new words and finding if a string matches any
previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or
false otherwise. word may contain dots '.' where dots can be matched with any letter.
*/

#include <iostream>
#include <string>
#include <unordered_map>

class WordDictionary {
private:
    struct Node;

    struct EndNodeInfo;

public:
    WordDictionary() : root(new Node()) {}

    ~WordDictionary() {
        delete root;
    }

    void addWord(const std::string &word) {
        auto [data_ind, word_ind, node_ptr] = findEndNode(word);
        std::string &data = node_ptr->data;
        if (node_ptr == root) {
            root->node_map.insert({word[0], new Node(true, word)});
            return;
        }
        if (data_ind == data.size() && word_ind == word.size()) {
            node_ptr->terminal = true;
            return;
        }
        if (data_ind < data.size()) {
            std::string new_data = data.substr(data_ind);
            Node *descendant_node = new Node(node_ptr->terminal, new_data);
            descendant_node->node_map = std::move(node_ptr->node_map);
            node_ptr->node_map.insert({new_data.front(), descendant_node});
            data = data.substr(0, data_ind);
            node_ptr->terminal = false;
        }
        if (word_ind == word.size()) {
            node_ptr->terminal = true;
        } else {
            node_ptr->node_map.insert({word[word_ind], new Node(true, word.substr(word_ind))});
        }
    }

    [[nodiscard]] bool search(const std::string &word) const noexcept {
        return isSuffixFound(word, 0, word.size(), root);
    }

private:
    [[nodiscard]] bool isSuffixFound(const std::string &word, std::size_t word_ind,
                                     const std::size_t &word_size, Node *curr_node) const noexcept {
        std::string &data = curr_node->data;
        std::size_t data_ind = 0;
        std::size_t data_size = data.size();
        while (data_ind < data_size && word_ind < word_size &&
               (data[data_ind] == word[word_ind] || word[word_ind] == '.')) {
            ++data_ind;
            ++word_ind;
        }
        if (data_ind == data_size) {
            if (word_ind == word_size && curr_node->terminal) {
                return true;
            }
            if (word_ind < word_size) {
                if (word[word_ind] == '.') {
                    for (const auto &item : curr_node->node_map) {
                        if (isSuffixFound(word, word_ind, word_size, item.second)) {
                            return true;
                        }
                    }
                } else if (curr_node->node_map.contains(word[word_ind])) {
                    return isSuffixFound(word, word_ind, word_size,
                                         curr_node->node_map[word[word_ind]]);
                }
            }
        }
        return false;
    }

    [[nodiscard]] EndNodeInfo findEndNode(const std::string &prefix) const noexcept {
        Node *curr_node = root;
        std::size_t pref_ind = 0;
        std::size_t prefix_size = prefix.size();
        while (pref_ind < prefix_size) {
            std::string &data = curr_node->data;
            std::size_t data_ind = 0;
            std::size_t data_size = data.size();
            while (data_ind < data_size && pref_ind < prefix_size &&
                   data[data_ind] == prefix[pref_ind]) {
                ++data_ind;
                ++pref_ind;
            }
            if (data_ind < data_size || pref_ind == prefix_size ||
                !curr_node->node_map.contains(prefix[pref_ind])) {
                return {.data_ind = data_ind, .pref_ind = pref_ind, .node_ptr = curr_node};
            }
            curr_node = curr_node->node_map[prefix[pref_ind]];
        }
        return {.data_ind = 0, .pref_ind = 0, .node_ptr = nullptr};
    }

    struct Node {
    public:
        Node() : terminal(false), data(), node_map() {}

        Node(bool terminal, const std::string &data) : terminal(terminal), data(data), node_map() {}

        ~Node() {
            for (const auto &item : node_map) {
                delete item.second;
            }
        }

        bool terminal;
        std::string data;
        std::unordered_map<char, Node *> node_map;
    };

    struct EndNodeInfo {
        std::size_t data_ind;
        std::size_t pref_ind;
        Node *node_ptr;
    };

    Node *root;
};

int main() {
    WordDictionary obj;
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");
    std::cout << obj.search("pad") << '\n';
    std::cout << obj.search("bad") << '\n';
    std::cout << obj.search(".ad") << '\n';
    std::cout << obj.search("b..") << '\n';
    return 0;
}