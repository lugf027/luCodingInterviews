/*************************************************************
 * Name     : 59_generateMatrix
 * Title    : 59. 螺旋矩阵 II
 * Author   : lugf027 10:48 AM 1/11/2021.
 * Describe :
 * 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 *************************************************************/

#include "util.h"

namespace generateMatrix{


    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res;
            // 设置数组大小
            vector<int> temp(n);
            res.resize(n, temp);

            int num = 1;

            for (int i = 0; i <= n / 2; ++i) {
                int distance = n - i - i - 1;
                for (int j = i; j < n - i; ++j) {
                    res[i][j] = num;
                    res[j][n - i - 1] = num + distance;
                    res[n - i - 1][n - j - 1] = num + distance + distance;
                    res[n - j - 1][i] = num + distance + distance + distance;
                    ++num;
                }
                num += distance * 3 + 1;
            }

            return res;
        }
    };

}
