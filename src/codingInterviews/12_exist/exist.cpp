/********************************************
* exist.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
 * 例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
 * [["a","b","c","e"],
 * ["s","f","c","s"],
 * ["a","d","e","e"]]
 * 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
 * 路径不能再次进入这个格子。
 */

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.at(i).size(); ++j) {
                if (dfs(board, word.c_str(), i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, const char *word, int i, int j, int k) {
        // 越界
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board.at(i).size() ||
            board.at(i).at(j) != word[k])
            return false;

        if (k == strlen(word) - 1)
            return true;

        char tmp = board[i][j];
        board[i][j] = '$';
        bool ret = dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i + 1, j, k + 1) ||
                   dfs(board, word, i, j - 1, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1);
        board[i][j] = tmp;

        return ret;
    }
};
