/********************************************
* validMountainArray.cpp                              *
* Created by lugf027 on 2020/11/3.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 941. 有效的山脉数组
/// 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
/// 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
/// A.length >= 3
///   在 0 < i < A.length - 1 条件下，存在 i 使得：
///    A[0] < A[1] < ... A[i-1] < A[i]
///    A[i] > A[i+1] > ... > A[A.length - 1]


#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int isUp = 2;

        for(int i = 1; i<A.size(); ++i){
            if((isUp == 2 || isUp == 1) && A[i] > A[i-1])
                isUp = 1;
            else if(isUp == 0 && A[i] < A[i-1])
                continue;
            else if(isUp == 1 && A[i] < A[i-1])
                isUp = 0;
            else
                return false;
        }

        return !isUp;
    }
};
