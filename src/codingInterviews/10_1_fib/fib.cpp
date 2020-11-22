/********************************************
* fib.cpp                              *
* Created by lugf027 on 2020/10/13.            *
* Github: https://github.com/lugf027        *
*********************************************/


/**
 * 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

    F(0) = 0,   F(1) = 1
    F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
    斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */

#include <vector>
#include <cstdlib>

namespace fib
{

    class Solution {
    public:
        /**
         * 动态规划、转化方程
         * @param n
         * @return
         */
        int fib(int n) {
            if (n == 0) return 0;
            if (n == 1) return 1;
            int *fibs = (int *) malloc((n + 1) * sizeof(int));

            fibs[0] = 0;
            fibs[1] = 1;
            for (int i = 2; i <= n; ++i) {
                fibs[i] = (fibs[i - 1] + fibs[i - 2]) % 1000000007;
            }

            return fibs[n];
        }

        /**
         * ...
         * @param n
         * @return
         */
        int fib2(int n){
            if (n == 0 || n == 1)
                return n;

            int a = 1, b = 0;
            for (int i = 1; i < n; i++) {
                a = a + b;
                b = a - b;
                a %= 1000000007;
            }
            return a;
        }

        /**
         * 创建数组
         * @param n
         * @return
         */
        int fib1(int n) {
            if (n == 0) {
                return 0;
            } else if (n == 1) {
                return 1;
            } else if (fibN[n] != 0) {
                return fibN[n];
            } else {
                fibN[n] = (fib(n - 1) + fib(n - 2)) % 1000000007;
                return fibN[n];
            }
        }

    private:
        int fibN[101] = {};

    };

//#include <iostream>

//    int main() {
//        Solution *solution = new Solution;
//
//        int a = 10;
//        int fibA1 = solution->fib1(a);
//        int fibA2 = solution->fib(a);
//
//        printf("%d\n%d\n", fibA1, fibA2);
//
//        return 0;
//    }

}
