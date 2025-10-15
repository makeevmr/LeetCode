#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
  [[nodiscard]] static std::vector<std::string> removeComments(
      const std::vector<std::string>& source) {
    std::vector<std::string> no_comments_source;
    std::string no_comments_line;
    bool in_block_comment = false;
    std::size_t line_ind = 0;
    const std::size_t lines = source.size();
    while (line_ind < lines) {
      do {
        no_comments_line +=
            getNoCommentsLine(source[line_ind++], in_block_comment);
      } while ((line_ind < lines) && in_block_comment);
      if (!no_comments_line.empty()) {
        no_comments_source.push_back(std::move(no_comments_line));
      }
    }
    return no_comments_source;
  }

private:
  static std::string getNoCommentsLine(const std::string& str,
                                       bool& in_block_comment) {
    if (str.empty()) {
      return "";
    }
    if (in_block_comment) {
      const auto block_end_ind = str.find("*/");
      if (block_end_ind == std::string::npos) {
        return "";
      }
      in_block_comment = false;
      return getNoCommentsLine(str.substr(block_end_ind + 2), in_block_comment);
    }
    const auto line_comment_ind = str.find("//");
    const auto block_comment_ind = str.find("/*");
    const auto min_ind = std::min(line_comment_ind, block_comment_ind);
    if (line_comment_ind < block_comment_ind) {
      return str.substr(0, min_ind);
    }
    if (min_ind == std::string::npos) {
      return str;
    }
    in_block_comment = true;
    return str.substr(0, min_ind) +
           getNoCommentsLine(str.substr(min_ind + 2), in_block_comment);
  }
};

#include <iostream>

int main() {
  std::vector<std::string> source = {"/*Test program */",
                                     "int main()",
                                     "{ ",
                                     "  // variable declaration ",
                                     "int a, b, c;",
                                     "/* This is a test",
                                     "   multiline  ",
                                     "   comment for ",
                                     "   testing */",
                                     "a = b + c;",
                                     "}"};
  std::vector<std::string> no_comments_source =
      Solution::removeComments(source);
  std::for_each(no_comments_source.begin(), no_comments_source.end(),
                [](const std::string& line) {
                  std::cout << line << '\n';
                });
  return 0;
}