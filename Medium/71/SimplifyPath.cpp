/* Given an absolute path for a Unix-style file system, which begins with a slash '/', transform
this path into its simplified canonical path.

In Unix-style file system context, a single period '.' signifies the current directory, a double
period ".." denotes moving up one directory level, and multiple slashes such as "//" are interpreted
as a single slash. In this problem, treat sequences of periods not covered by the previous rules
(like "...") as valid names for files or directories.

The simplified canonical path should adhere to the following rules:

It must start with a single slash '/'.
Directories within the path should be separated by only one slash '/'.
It should not end with a slash '/', unless it's the root directory.
It should exclude any single or double periods used to denote current or parent directories.
Return the new path.
Time complexity: O(n), where n is length of path
Additional memory complexiy: O(n)
Idea: use stack to store path in right order
*/

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    static std::string simplifyPath(const std::string &path) {
        std::string curr_direcory;
        std::size_t path_size = path.size();
        std::stack<std::string> simplified_path;
        for (std::size_t i = 0; i < path_size; ++i) {
            if (path[i] == '/') {
                changePath(simplified_path, curr_direcory);
            } else {
                curr_direcory.push_back(path[i]);
            }
        }
        changePath(simplified_path, curr_direcory);
        std::stack<std::string> reversed_path;
        while (!simplified_path.empty()) {
            reversed_path.push(std::move(simplified_path.top()));
            simplified_path.pop();
        }
        std::string answer;
        while (!reversed_path.empty()) {
            answer.push_back('/');
            answer += std::move(reversed_path.top());
            reversed_path.pop();
        }
        if (answer.empty()) {
            answer.push_back('/');
        }
        return answer;
    }

private:
    static void changePath(std::stack<std::string> &simplified_path, std::string &curr_direcory) {
        if (!curr_direcory.empty()) {
            if (curr_direcory == "..") {
                if (!simplified_path.empty()) {
                    simplified_path.pop();
                }
            } else if (curr_direcory != ".") {
                simplified_path.push(std::move(curr_direcory));
            }
        }
        curr_direcory.clear();
    }
};

int main() {
    // std::string path = "/home/";
    // std::string path = "/home//foo/";
    // std::string path = "/home/user/Documents/../Pictures";
    // std::string path = "/../";
    std::string path = "/.../a/../b/c/../d/./";
    std::cout << Solution::simplifyPath(path) << '\n';
    return 0;
}
