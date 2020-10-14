/********************************************
* numWays.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */

#include <cstdlib>

class Solution {
public:
    /**
     * 动态规划
     * @param n
     * @return
     */
    int numWays(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int *nums = (int *) malloc((n + 1) * sizeof(int));
        nums[0] = 1;
        nums[1] = 1;

        for (int i = 2; i <= n; ++i) {
            nums[i] = (nums[i - 1] + nums[i - 2]) % 1000000007;
        }

        return nums[n];
    }
};

int main(){
    Solution solution;
    int a = solution.numWays(2);


    return 0;
}
