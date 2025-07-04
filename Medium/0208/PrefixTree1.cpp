/* A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store
and retrieve keys in a dataset of strings. There are various applications of this data structure,
such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted
before), and false otherwise. boolean startsWith(String prefix) Returns true if there is a
previously inserted string word that has the prefix prefix, and false otherwise.
Time complexity: insert(O(n)), search(O(n)), startsWith(O(n))
Additional memory complexity: O(n)
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Trie {
private:
    struct Node;

    struct EndNodeInfo;

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const std::string &word) {
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
        auto [data_ind, word_ind, node_ptr] = findEndNode(word);
        return (data_ind == node_ptr->data.size()) && (word_ind == word.size()) &&
               (node_ptr->terminal);
    }

    [[nodiscard]] bool startsWith(const std::string &prefix) const noexcept {
        return findEndNode(prefix).pref_ind == prefix.size();
    }

private:
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
    // Trie trie;
    // trie.insert("apple");
    // std::cout << trie.search("apple") << '\n' << '\n';
    // std::cout << trie.search("app") << '\n' << '\n';
    // std::cout << trie.startsWith("app") << '\n' << '\n';
    // trie.insert("app");
    // std::cout << trie.search("app") << '\n';

    // Trie trie;
    // trie.insert("ab");
    // std::cout << trie.search("abc") << '\n';
    // std::cout << trie.search("ab") << '\n';
    // std::cout << trie.startsWith("abc") << '\n';
    // std::cout << trie.startsWith("ab") << '\n';
    // trie.insert("ab");
    // std::cout << trie.search("abc") << '\n';
    // std::cout << trie.startsWith("abc") << '\n';
    // trie.insert("abc");
    // std::cout << trie.search("abc") << '\n';
    // std::cout << trie.startsWith("abc") << '\n';

    // Trie trie;
    // trie.insert("app");
    // trie.insert("apple");
    // trie.insert("beer");
    // trie.insert("add");
    // trie.insert("jam");
    // trie.insert("rental");
    // std::cout << trie.search("apps") << '\n';
    // std::cout << trie.search("app") << '\n';
    // std::cout << trie.search("ad") << '\n';
    // std::cout << trie.search("applepie") << '\n';
    // std::cout << trie.search("rest") << '\n';
    // std::cout << trie.search("jan") << '\n';
    // std::cout << trie.search("rent") << '\n';
    // std::cout << trie.search("beer") << '\n';
    // std::cout << trie.search("jam") << '\n';
    // std::cout << trie.startsWith("apps") << '\n';
    // std::cout << trie.startsWith("app") << '\n';
    // std::cout << trie.startsWith("ad") << '\n';
    // std::cout << trie.startsWith("applepie") << '\n';
    // std::cout << trie.startsWith("rest") << '\n';
    // std::cout << trie.startsWith("jan") << '\n';
    // std::cout << trie.startsWith("rent") << '\n';
    // std::cout << trie.startsWith("beer") << '\n';
    // std::cout << trie.startsWith("jam") << '\n';

    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("werwr");
    trie.insert("add");
    trie.insert("adk");
    trie.insert("aaaaa");
    trie.insert("adq");
    std::cout << trie.search("app") << '\n';
    std::cout << trie.search("apple") << '\n';
    std::cout << trie.search("add") << '\n';
    std::cout << trie.search("adk") << '\n';
    std::cout << trie.search("adq") << '\n';
    std::cout << trie.search("ads") << '\n';
    std::cout << trie.search("applem") << '\n';
    std::cout << trie.search("aaaaa") << '\n';
    std::cout << trie.search("werwr") << '\n';
    std::cout << trie.search("a") << '\n';
    std::cout << trie.search("ad") << '\n';
    return 0;
}