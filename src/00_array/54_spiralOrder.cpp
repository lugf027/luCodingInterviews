/*************************************************************
 * Name     : 54_spiralOrder
 * Title    : 54. 螺旋矩阵
 * Author   : lugf027 3:26 PM 1/11/2021.
 * Describe :
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *************************************************************/

#include "util.h"

namespace spiralOrder {

    /**
     * 一层层遍历
     */
    class Solution2 {
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            vector<int> res;
            if (matrix.empty() || matrix[0].empty()) {
                return res;
            }
            int rows = matrix.size();
            int columns = matrix[0].size();

            int left = 0;
            int right = columns - 1;
            int top = 0;
            int bottom = rows - 1;

            while (left <= right && top <= bottom) {
                for (int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
                for (int i = top + 1; i <= bottom; ++i) res.push_back(matrix[i][right]);

                if (left < right && top < bottom) {
                    for (int i = right - 1; i >= left; --i) res.push_back(matrix[bottom][i]);
                    for (int i = bottom - 1; i > top; --i) res.push_back(matrix[i][left]);
                }
                ++left;
                --right;
                ++top;
                --bottom;
            }
            return res;
        }
    };


    /**
     * 辅助矩阵记录已遍历
     */
    class Solution11 {
    private:
        static constexpr int directions[4][2] = {{0,  1},
                                                 {1,  0},
                                                 {0,  -1},
                                                 {-1, 0}};

    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            vector<int> res;
            if (matrix.empty() || matrix[0].empty()) {
                return res;
            }
            int rows = matrix.size();
            int columns = matrix[0].size();

            vector<vector<bool>> visited(rows, vector<bool>(columns));

            int rowNow = 0;
            int columnNow = 0;
            int directionNow = 0;
            for (int i = 0; i < rows * columns; ++i) {
                res.push_back(matrix[rowNow][columnNow]);
                visited[rowNow][columnNow] = true;
                int rowNext = rowNow + directions[directionNow][0];
                int columnNext = columnNow + directions[directionNow][1];

                if (rowNext < 0 || rowNext >= rows || columnNext < 0 || columnNext >= columns
                    || visited[rowNext][columnNext]) {
                    directionNow = (directionNow + 1) % 4;
                }

                rowNow += directions[directionNow][0];
                columnNow += directions[directionNow][1];
            }
            return res;
        }
    };

    /**
     * 错误
     */
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            vector<int> res;
            int m = matrix.size();
            int n = matrix[0].size();
            for (int i = 0; i < (m + 1) / 2 && i < (n + 1) / 2; ++i) {
                for (int j = i; j <= n - i - 1; ++j) res.push_back(matrix[i][j]);
                for (int j = i + 1; j <= m - i - 1; ++j) res.push_back(matrix[j][n - i - i - 1]);

                if (i * 2 + 1 != m && i * 2 + 1 != n) {
                    for (int j = n - i - 1 - 1; j >= i; --j) res.push_back(matrix[m - i - 1][j]);
                    for (int j = m - i - 1 - 1; j > i; --j) res.push_back(matrix[j][i]);
                }
            }
            return res;
        }
    };
}
