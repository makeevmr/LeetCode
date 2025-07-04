// Given an array of strings words and a width maxWidth, format the text such that each line has
// exactly maxWidth characters and is fully (left and right) justified.
// Time complexity solution: O(n), where n is number of words
// Additional memory complexity: O(1)

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static std::vector<std::string> fullJustify(std::vector<std::string> &words, int max_width) {
        int words_amount = static_cast<int>(words.size());
        int curr_word = 0;
        std::size_t u_max_width = static_cast<std::size_t>(max_width);
        std::string justified_line;
        std::vector<std::string> justified_text;
        while (curr_word < words_amount) {
            int start_line_word = curr_word;
            int symbols_amount = getSymbolsAmount(words, curr_word, u_max_width);
            if (curr_word == words_amount) {
                pushJustifiedLine(words, justified_text, justified_line, u_max_width,
                                  start_line_word, curr_word, 1, 0);
            } else {
                int words_in_line = curr_word - start_line_word;
                std::size_t space_length = 0;
                std::size_t additional_space_amount = 0;
                if (words_in_line > 1) {
                    space_length = (u_max_width - symbols_amount) /
                                   (static_cast<std::size_t>(words_in_line - 1));
                    additional_space_amount = (u_max_width - symbols_amount) %
                                              (static_cast<std::size_t>(words_in_line - 1));
                }
                pushJustifiedLine(words, justified_text, justified_line, u_max_width,
                                  start_line_word, curr_word, space_length,
                                  additional_space_amount);
            }
        }
        return justified_text;
    }

private:
    static std::size_t getSymbolsAmount(const std::vector<std::string> &words, int &curr_word,
                                        std::size_t u_max_width) {
        int words_amount = static_cast<int>(words.size());
        std::size_t line_length = 0;
        std::size_t symbols_amount = 0;
        line_length += words[curr_word].size();
        symbols_amount += words[curr_word].size();
        ++curr_word;
        while (curr_word < words_amount &&
               ((line_length + 1 + words[curr_word].size()) <= u_max_width)) {
            line_length += 1 + words[curr_word].size();
            symbols_amount += words[curr_word].size();
            ++curr_word;
        }
        return symbols_amount;
    }

    static void pushJustifiedLine(std::vector<std::string> &words,
                                  std::vector<std::string> &justified_text,
                                  std::string &justified_line, std::size_t u_max_width,
                                  int start_line_word, int curr_word, int space_length,
                                  int additional_space_amount) {
        justified_line.append(std::move(words[start_line_word++]));
        while (start_line_word < curr_word) {
            if (additional_space_amount > 0) {
                --additional_space_amount;
                justified_line += std::string(space_length + 1, ' ');
            } else {
                justified_line += std::string(space_length, ' ');
            }
            justified_line.append(std::move(words[start_line_word++]));
        }
        justified_line += std::string(u_max_width - justified_line.size(), ' ');
        justified_text.push_back(std::move(justified_line));
    }
};

int main() {
    // std::vector<std::string> words = {"This",          "is", "an", "example", "of", "text",
    //                                   "justification."};
    // int max_width = 16;
    // std::vector<std::string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    // int max_width = 16;
    std::vector<std::string> words = {
        "Science", "is", "what",      "we",  "understand", "well",       "enough", "to", "explain",
        "to",      "a",  "computer.", "Art", "is",         "everything", "else",   "we", "do"};
    int max_width = 20;
    std::vector<std::string> justified_text = Solution::fullJustify(words, max_width);
    for (const auto &str : justified_text) {
        std::cout << str << '\n';
    }
    return 0;
}