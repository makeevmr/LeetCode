/* A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings. There are various
applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise. boolean startsWith(String
prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise. Time complexity: insert(O(n)), search(O(n)),
startsWith(O(n)) Additional memory complexity: O(n)
*/

#include <iostream>
#include <unordered_map>

class Trie {
private:
  struct Node;

public:
  Trie()
      : root(new Node()) {}

  ~Trie() {
    delete root;
  }

  void insert(const std::string& word) {
    Node* curr_node = root;
    std::size_t ind = 0;
    while (curr_node->node_map.contains(word[ind])) {
      curr_node = curr_node->node_map[word[ind]];
      ++ind;
    }
    std::size_t word_size = word.size();
    for (; ind < word_size; ++ind) {
      curr_node->node_map[word[ind]] = new Node();
      curr_node = curr_node->node_map[word[ind]];
    }
    curr_node->terminal = true;
  }

  [[nodiscard]] bool search(const std::string& word) const noexcept {
    Node* curr_node = getNode(word);
    if (curr_node == nullptr) {
      return false;
    }
    return curr_node->terminal;
  }

  [[nodiscard]] bool startsWith(const std::string& prefix) const noexcept {
    return getNode(prefix) != nullptr;
  }

private:
  [[nodiscard]] Node* getNode(const std::string& prefix) const noexcept {
    Node* curr_node = root;
    for (const auto& symbol : prefix) {
      if (!curr_node->node_map.contains(symbol)) {
        return nullptr;
      }
      curr_node = curr_node->node_map[symbol];
    }
    return curr_node;
  }

  struct Node {
  public:
    Node()
        : terminal(false),
          node_map() {}

    ~Node() {
      for (const auto& item : node_map) {
        delete item.second;
      }
    }

    bool terminal;
    std::unordered_map<char, Node*> node_map;
  };

  Node* root;
};

int main() {
  Trie trie;
  trie.insert("apple");
  std::cout << trie.search("apple") << '\n';
  std::cout << trie.search("app") << '\n';
  std::cout << trie.startsWith("app") << '\n';
  trie.insert("app");
  std::cout << trie.search("app") << '\n';
  return 0;
}
