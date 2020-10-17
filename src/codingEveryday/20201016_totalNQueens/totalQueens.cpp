/********************************************
* totalQueens.cpp                              *
* Created by lugf027 on 2020/10/17.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <vector>
#include <string>
#include <unordered_set>

/// 52. 给定一个整数 n，返回 n 皇后不同的解决方案的数量。

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
    int totalNQueens(int n) {
        auto columns = unordered_set<int>();        // 列
        auto diagonals1 = unordered_set<int>();     // 斜线1
        auto diagonals2 = unordered_set<int>();     // 斜线2

        return backtrack(n, 0, columns, diagonals1, diagonals2);
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
    int backtrack(int n, int row, unordered_set<int> &columns,
                  unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int resCount = 0;
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

                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);

                resCount += backtrack(n, row + 1, columns, diagonals1, diagonals2);

                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
            return resCount;
        }
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
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

private:
    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int resCount = 0;
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                resCount += solve(n, row + 1, columns | position,
                                  (diagonals1 | position) >> 1,  /* 左上到右下，每往下一行右移一次*/
                                  (diagonals2 | position) << 1   /* 左下到右上，每往下一行左移一次*/
                );
            }
            return resCount;
        }
    }
};

/**
    x & (−x) 可以获得 x 的二进制表示中的最低位的 1 的位置；
    x &  (x-1) 可以将 x 的二进制表示中的最低位的 1 置成 0。
 */

