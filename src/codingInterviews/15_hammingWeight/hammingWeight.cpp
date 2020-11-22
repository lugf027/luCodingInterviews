/********************************************
* hammingWeight.cpp                              *
* Created by lugf027 on 2020/10/18.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <cstdint>

/// 剑指 Offer 15. 二进制中1的个数
/// 请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
/// 例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

namespace hammingWeight {

/**
 * 移位
 * 4ms
 */
    class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int res = 0;
            while (n) {
                res += n & 1;
                n >>= 1;
            }
            return res;
        }
    };


/**
 * 巧用 n \& (n - 1)n&(n−1)
 *  (n - 1)   解析： 二进制数字 n 最右边的 1 变成 0 ，此 1 右边的 0 都变成 1 。
 *  n & (n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，其余不变。
 *  0ms
 */
    class Solution1 {
    public:
        int hammingWeight(uint32_t n) {
            int res = 0;
            while (n) {
                ++res;
                n = n & (n - 1);
            }
            return res;
        }
    };

}