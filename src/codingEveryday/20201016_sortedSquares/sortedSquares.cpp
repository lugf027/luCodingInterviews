/********************************************
* sortedSquares.cpp                              *
* Created by lugf027 on 2020/10/16.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 给定一个按非递减顺序排序的整数数组 A，
/// 返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

#include <vector>
#include <stack>

#include<algorithm>

using namespace std;

class Solution {
public:
    /**
     * 用栈存负数的平方，并使栈顶与正数的平方依次比较
     * @param A
     * @return
     */
    vector<int> sortedSquares(vector<int>& A) {
        stack<int> temps;
        vector<int> res;
        for(int i: A){
            if(i < 0){
                temps.push(i * i);
            }else{
                int i_i = i * i;

                while(!temps.empty() && temps.top() < i_i){
                    res.push_back(temps.top());
                    temps.pop();
                }
                res.push_back(i_i);
            }
        }
        while(!temps.empty()){
            res.push_back(temps.top());
            temps.pop();
        }

        return res;
    }

    /**
     * 直接排序
     * @param A
     * @return
     */
    vector<int> sortedSquares1(vector<int>& A) {
        vector<int> ans;
        for (int num: A) {
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    /**
     * 双指针，指向原数组
     * @param A
     * @return
     */
    vector<int> sortedSquares2(vector<int>& A) {
        int n = A.size();
        int negative = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n) {
            if (i < 0) {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
            else if (j == n) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else if (A[i] * A[i] < A[j] * A[j]) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
        }

        return ans;
    }

    /**
     * 双指针，指向结果数组
     * @param A
     * @return
     */
    vector<int> sortedSquares3(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (A[i] * A[i] > A[j] * A[j]) {
                ans[pos] = A[i] * A[i];
                ++i;
            }
            else {
                ans[pos] = A[j] * A[j];
                --j;
            }
            --pos;
        }
        return ans;
    }

};
