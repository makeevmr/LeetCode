/* Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once in a
word.
*/

#include <string>
#include <vector>

class Solution {
private:
public:
    static std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                              const std::vector<std::string>& words) {
        Trie<ALPHABET_SIZE> trie(words);
        std::vector<std::string> words_in_board;
        std::string curr_word;
        const int board_rows = static_cast<int>(board.size());
        const int board_columns = static_cast<int>(board.front().size());
        for (int row = 0; row < board_rows; ++row) {
            for (int column = 0; column < board_columns; ++column) {
                if (trie.root->descendant[board[row][column] - 'a']) {
                    std::string cell_id = std::to_string(row) + ":" + std::to_string(column);
                    DFS(board, words_in_board, curr_word,
                        trie.root->descendant[board[row][column] - 'a'], board_rows, board_columns,
                        row, column);
                }
            }
        }
        return words_in_board;
    }

private:
    template <std::size_t N>
    class Trie {
    public:
        Trie(const std::vector<std::string>& words)
            : root(new Node()) {
            std::size_t words_size = words.size();
            for (std::size_t i = 0; i < words_size; ++i) {
                Node* curr_node = root;
                for (const auto& symbol : words[i]) {
                    int index = static_cast<int>(symbol - 'a');
                    if (curr_node->descendant[index] == nullptr) {
                        curr_node->descendant[index] = new Node();
                    }
                    curr_node = curr_node->descendant[index];
                }
                curr_node->terminal = true;
            }
        }

        ~Trie() {
            delete root;
        }

        class Node {
        public:
            Node()
                : terminal(false) {
                for (std::size_t i = 0; i < N; ++i) {
                    descendant[i] = nullptr;
                }
            }

            Node(bool terminal)
                : terminal(terminal) {
                for (std::size_t i = 0; i < N; ++i) {
                    descendant[i] = nullptr;
                }
            }

            ~Node() {
                for (std::size_t i = 0; i < N; ++i) {
                    delete descendant[i];
                }
            }

            bool terminal;
            Node* descendant[N];
        };

        Node* root;
    };

    static const int ALPHABET_SIZE = 26;

    static const std::vector<std::pair<int, int>> offset;

    static void DFS(std::vector<std::vector<char>>& board, std::vector<std::string>& words_in_board,
                    std::string& curr_word, Trie<ALPHABET_SIZE>::Node* curr_node,
                    const int& board_rows, const int& board_columns, int row, int column) {
        curr_word.push_back(board[row][column]);
        board[row][column] = '#';
        if (curr_node->terminal) {
            curr_node->terminal = false;
            words_in_board.push_back(curr_word);
        }
        for (const auto& pair : offset) {
            int new_row = row + pair.first;
            int new_column = column + pair.second;
            if ((0 <= new_row) && (new_row < board_rows) && (0 <= new_column) &&
                (new_column < board_columns) && board[new_row][new_column] != '#' &&
                curr_node->descendant[board[new_row][new_column] - 'a']) {
                DFS(board, words_in_board, curr_word,
                    curr_node->descendant[board[new_row][new_column] - 'a'], board_rows,
                    board_columns, new_row, new_column);
            }
        }
        board[row][column] = curr_word.back();
        curr_word.pop_back();
    }
};

const std::pair<int, int> offset_array[4] = {std::pair<int, int>{-1, 0}, std::pair<int, int>{0, 1},
                                             std::pair<int, int>{1, 0}, std::pair<int, int>{0, -1}};

const std::vector<std::pair<int, int>> Solution::offset(offset_array, offset_array + 4);
