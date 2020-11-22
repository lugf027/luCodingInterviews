/********************************************
* findNumberIn2DArray.cpp                              *
* Created by lugf027 on 2020/10/12.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <vector>

using namespace std;

/**
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    示例:
        现有矩阵 matrix 如下：
        [
          [1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]
        ]
        给定 target = 5，返回 true。
        给定 target = 20，返回 false。
    限制：
        0 <= n <= 1000
        0 <= m <= 1000
 */

namespace findNumberIn2DArray {

    class Solution {
    public:

        /**
         * 暴力查找略
         */

        /**
         * 线性查找、二叉搜索树
         * @param matrix
         * @param target
         * @return
         */
        bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
            // 自己第一次忽略了外层为 零 的情况。
            if (matrix.empty()) {
                return false;
            }

            int row = 0;
            int column = matrix.at(0).size() - 1;
            while (row < matrix.size() && column >= 0) {
                if (matrix.at(row).at(column) > target) {
                    --column;
                }
                else if (matrix.at(row).at(column) < target) {
                    ++row;
                }
                else {
                    return true;
                }
            }

            return false;
        }
    };
}
