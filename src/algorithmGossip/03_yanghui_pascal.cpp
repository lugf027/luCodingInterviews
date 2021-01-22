/*************************************************************
 * Name     : 03_yanghui_pascal
 * Title    : 03_杨辉三角/ _帕斯卡三角形
 * Author   : lugf027 21:44 2021/1/16.
 * Describe :
 * 杨辉三角-最终优化 (Maybe there is a better solution)
 *************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * 组合 C(n, m)
 * @param n
 * @param m
 * @return
 */
long combination(int n, int m) {
    // C(n, m) == C(n, n-m)
    if (m > (n >> 1)) {
        m = n - m;
    }
    long res = 1;
    for (int i = 1; i <= m; ++i)
        res = res * (n - i + 1) / i;
    return res;
}

int getLargestNumLen(int lineNum) {
    // 杨辉三角第 N 行为 C(n-1, x), 但与下面求最大值时 (n+1)/2 抵消
    //--lineNum;
    long num = 1;
    for (int i = 1; i <= ((lineNum /*+ 1*/) >> 1); ++i)
        num = num * (lineNum - i /*+ 1*/) / i;
    int res = 0;
    while (num) {
        num = num / 10;
        ++res;
    }
    return res;
}

void printPascal(int lineNum) {
    int spaceNum = getLargestNumLen(lineNum);
    for (int row = 0; row < lineNum; ++row) {
        for (int column = 0; column <= row; ++column) {
            // spaces (to jump behinds & between two number)
            if (column == 0) {
                for (int spaceToJump = 0; spaceToJump < (lineNum - row) - 1; spaceToJump++)
                    cout << setw(spaceNum) << " ";
            } else {
                cout << setw(spaceNum) << " ";
            }
            cout << setw(spaceNum) << combination(row, column);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Please input number of sheet:" << endl;
    cin >> n;
    printPascal(n);
    return 0;
}


