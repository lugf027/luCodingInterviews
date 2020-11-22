/********************************************
* cuttingRope.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 * 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，
 * 我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */

#include <algorithm>
#include <cmath>

using namespace std;

namespace cuttingRope{

    class Solution {
    public:

        /**
         * 动态规划
         * @param n
         * @return
         */
        int cuttingRope(int n) {
            int *dp = new int[n + 1];
            // 注意初始化
            for (int i = 0; i <= n; ++i) {
                dp[i] = 0;
            }
            for (int i = 2; i <= n; ++i) {
                for (int j = 1; j < i; ++j) {
                    dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                }
            }
            return dp[n];
        }

        /**
         * 函数极值,不知道为什么这个慢一些
            直觉上把数拆的越平均他们的积越大。拆分的整数越接近自然参数e，他们的乘积的越大。
    数学证明：定义函数 f(x) 表示将给定的正整数 n 拆分成尽可能多的正数 x 的情况下的最大乘积，则可以将 n 分成 x/n项，
            此时 f(x)=x^(x/n)，通过求导可得f(x)在x=e时取最大值，f(3)>f(2)，x=3 时，可以得到最大乘积。

            根据 n 除以 3 的余数进行分类讨论：
                如果余数为 0，则将 n 拆分成 m 个 3；
                如果余数为 1，因此将 n 拆分成 m-1 个 3 和 2 个 2；
                如果余数为 2，则将 n 拆分成 m 个 3 和 1 个 2。

            上述拆分的适用条件是 n≥4。如果 n≤3，则上述拆分不适用，需要单独处理
                如果 n=2，则唯一的拆分方案是 2=1+1，最大乘积是 1×1=1；
                如果 n=3，则拆分方案有 3=1+2=1+1+1，最大乘积对应方案 3=1+2，最大乘积是1×2=2
                这两种情形可以合并为：当 n≤3 时，最大乘积是 n-1。
         */
        int cuttingRope1(int n) {
            if (n <= 3)
                return n - 1;
            int quotient = n / 3;
            int remainder = n % 3;
            switch (remainder) {
                case 0:
                    return (int) pow(3, quotient);
                case 1:
                    return (int) pow(3, quotient - 1) * 4;
                case 2:
                    return (int) pow(3, quotient) * 2;
                default:
                    return -1;
            }
        }
    };

}
