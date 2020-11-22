/********************************************
* printNumbers.cpp                              *
* Created by lugf027 on 2020/10/18.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 17. 打印从1到最大的n位数
/// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
/// 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

#include <vector>
#include <cmath>

using namespace std;

namespace printNumbers{

/**
 * 最基本的办法？竟然能通过，n 似乎很小的，没有考虑大数？
 */
    class Solution {
    public:
        vector<int> printNumbers(int n) {
            n = pow(10, n);
            auto *res = new vector<int>();
            for (int i = 1; i < n; ++i) {
                res->push_back(i);
            }
            return *res;
        }
    };

#include <string>

/**
 * 大数版本
 */
    class Solution1{
    public:
        void printNumbers(int n,int index,string& str,vector<int> &res) {
            if (index == n) {
                int num = atoi(str.c_str());
                if (num != 0) res.push_back(num);
                return;
            }

            for (int i = 0;i < 10;i++) {
                // 每一位 从0到9依次排列
                // eg: 0, 00, 000, 001, 002, 003,
                str[index] = i + '0';
                printNumbers(n, index+1, str, res);
            }
        }

        vector<int> printNumbers(int n) {
            vector<int> res;
            string str;
            str.resize(n);

            printNumbers(n, 0, str, res);
            return res;
        }
    };

}