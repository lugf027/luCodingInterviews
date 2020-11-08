/********************************************
* maxProfit.cpp                              *
* Created by lugf027 on 2020/11/8.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 122. 买卖股票的最佳时机 II
/// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
/// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
/// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

#include <vector>

using namespace std;

/**
 * 贪心？
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] - prices[i - 1] > 0)
                res += prices[i] - prices[i - 1];

        return res;
    }
};

/**
 * 动态规划
 * 考虑到「不能同时参与多笔交易」，因此每天交易结束后只可能存在手里有一支股票或者没有股票的状态。
 * 定义状态 dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，
 * 定义状态 dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）。
 */
class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

