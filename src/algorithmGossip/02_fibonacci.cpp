/*************************************************************
 * Name     : 02_fibonacci
 * Title    : 02费式数列
 * Author   : lugf027 21:18 2021/1/16.
 * Describe :
 * 有一只免子每个月生一只小免子，一个月后小免子也开始生产。
 * 起初只有一只免子，一个月后就有两只免子，二个月后有三只免子，三个月后有五只免子（小免子投入生产）。。。
 * F(n) = F(n-1) + F(n-2)    n > 1
 * F(n) = n                  n = 0, 1
 *************************************************************/

#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) return n;
    int fibRes = 1;
    int finResPre = 0;
    for (int i = 1; i < n; ++i) {
        fibRes = fibRes + finResPre;
        finResPre = fibRes - finResPre;
    }
    return fibRes;
}

int fib_(int n) {
    if(n == 0 || n==1) return n;
    else return fib_(n-1)+fib_(n-2);
}

int main() {
    int fibNum = 8;
    cout << "fib " << fibNum << " is: " << fib(fibNum) << endl;
    cout << "fib_" << fibNum << " is: " << fib_(fibNum) << endl;
    return 0;
}
