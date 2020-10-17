/********************************************
* solveNQueens.cpp                              *
* Created by lugf027 on 2020/10/17.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <vector>
#include <string>
#include <unordered_set>

/// 51. 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
/// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

using namespace std;

/**
 * 基于集合的回溯
 * 时间复杂度：O(N!)，其中 N 是皇后数量。
 * 空间复杂度：O(N)，其中 N 是皇后数量。
 */
class Solution {
public:
    /**
     * 函数 api
     * @param n
     * @return
     */
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();  // 解法返回
        auto queens = vector<int>(n, -1);     // 棋盘
        auto columns = unordered_set<int>();        // 列
        auto diagonals1 = unordered_set<int>();     // 斜线1
        auto diagonals2 = unordered_set<int>();     // 斜线2

        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

private:
    /**
     * 回溯、基于集合的回溯
     * @param solutions
     * @param queens
     * @param n
     * @param row
     * @param columns
     * @param diagonals1
     * @param diagonals2
     */
    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row,
                   unordered_set<int> &columns,
                   unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            for (int i = 0; i < n; ++i) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }

                // 行下标与列下标之差即可明确表示每一条 左上到右下 方向的斜线，斜线不同，差值不同
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }

                // 行下标与列下标之和即可明确表示每一条 左下到右上 方向的斜线，斜线不同，差值不同
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }

                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);

                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);

                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }


    }

    /**
     * 格式化生成要返回的棋盘、基于集合的回溯
     * @param queens 第 i 行皇后所在列位置
     * @param n 棋盘大小
     * @return 格式化生成要返回的棋盘
     */
    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; ++i) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

/**
 * 基于位运算的回溯
 */
class Solution1 {
public:
    /**
     * 函数 api
     * @param n
     * @return
     */
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1,
               int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);

                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position,
                      (diagonals1 | position) >> 1,  /* 左上到右下，每往下一行右移一次*/
                      (diagonals2 | position) << 1   /* 左下到右上，每往下一行左移一次*/
                );
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

/**
    x & (−x) 可以获得 x 的二进制表示中的最低位的 1 的位置；
    x &  (x-1) 可以将 x 的二进制表示中的最低位的 1 置成 0。
 */

/**
    •int __builtin_ffs (unsigned int x)
    返回x的最后一位1的是从后向前第几位，比如7368（1110011001000）返回4。

    •int __builtin_clz (unsigned int x)
    返回前导的0的个数。

    •int __builtin_ctz (unsigned int x)
    返回后面的0个个数，和__builtin_clz相对。

    •int __builtin_popcount (unsigned int x)
    返回二进制表示中1的个数。

    •int __builtin_parity (unsigned int x)
    返回x的奇偶校验位，也就是x的1的个数模2的结果。

    此外，这些函数都有相应的usigned long和usigned long long版本，
    只需要在函数名后面加上l或ll就可以了，比如int __builtin_clzll
 */
