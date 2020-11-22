/********************************************
* lastRemaining.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 62. 圆圈中最后剩下的数字
/// 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。
/// 求出这个圆圈里剩下的最后一个数字。
/// 1 <= n <= 10^5
/// 1 <= m <= 10^6

#include <list>
#include <vector>

using namespace std;

namespace lastRemaining {
    /**
     * 超时
     * 71989
     * 111059
     */
    class Solution {
    public:
        int lastRemaining(int n, int m) {
            vector<int> nList;
            for (int i = 0; i < n; ++i) nList.push_back(i);

            int removeNow = 0;
            while (n > 1) {
                removeNow = (removeNow + m - 1) % n;
                nList.erase(nList.begin()+removeNow);
                --n;
            }
            return nList[0];
        }

    };

    /**
     * 反推
     * (此轮过后的 num 下标 + m ) % 上轮元素个数 = 上轮 num 的下标
     */
    class Solution1 {
    public:
        int lastRemaining(int n, int m) {
            int ans = 0;
            // 最后一轮剩下2个人，所以从2开始反推
            for (int i = 2; i <= n; ++i) {
                ans = (ans + m) % i;
            }
            return ans;
        }
    }

}
