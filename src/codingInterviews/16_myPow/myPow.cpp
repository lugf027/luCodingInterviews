/********************************************
* myPow.cpp                              *
* Created by lugf027 on 2020/10/18.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 16. 数值的整数次方
/// 实现函数double Power(double base, int exponent)，求base的exponent次方。
/// 不得使用库函数，同时不需要考虑大数问题。

/**
 * 快速幂解析（二进制角度）
 * 其实也是递归的非递归实现
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;

        long b = n;
        double res = 1.0;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }

        while (b) {
            if (b & 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};

/**
 * 递归
 */
class Solution1 {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        //如果n小于0，把它改为正数，并且把1/x提取出来一个
        if (n < 0) {
            return 1 / x * myPow(1 / x, -(n + 1));

            // 当n=Integer.MIN_VALUE的时候，代码就会出问题，这是因为数字溢出问题，导致Integer.MIN_VALUE的相反数还是他自己，
            // return myPow(1 / x, -n);

            // runtime error: negation of -2147483648 cannot be represented in type 'int';
            // cast to an unsigned type to negate this value to itself (solution.cpp)
            // return 1 / x * myPow(1 / x, -n - 1);
        }

        return (n % 2 == 0) ?
               myPow(x * x, n / 2) :
               x * myPow(x * x, n / 2);
    }
};
