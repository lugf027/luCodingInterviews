/********************************************
* sortByBits.cpp                              *
* Created by lugf027 on 2020/11/6.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 1356. 根据数字二进制下 1 的数目排序
/// 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
/// 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
/// 请你返回排序后的数组。

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> bits(10001, 0);
        for (int i:arr)
            bits[i] = judgeNum(i);

        sort(arr.begin(), arr.end(), [&](int x, int y)
        {
            if (bits[x] < bits[y])
            {
                return true;
            }
            if (bits[x] > bits[y])
            {
                return false;
            }
            return x < y;
        });
        return arr;
    }

private:
    int judgeNum(int i)
    {
        int count = 0;
        while (i)
        {
            count +=(i%2) ;
            i /= 2;
        }
        return count;
    }

};


#include <functional>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // sort using the default operator<
    std::sort(s.begin(), s.end());
    for (auto a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    // sort using a standard library compare function object
    std::sort(s.begin(), s.end(), std::greater<int>());
    for (auto a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    // sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {
            return a < b;
        }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    for (auto a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    // sort using a lambda expression
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
    });
    for (auto a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';
}
