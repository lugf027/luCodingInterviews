/*************************************************************
 * Name     : 01_towerOfHanoi
 * Title    : 1.河内之塔/ 汉诺塔
 * Author   : lugf027 20:02 2021/1/16.
 * Describe :
 * 创世纪时Benares有一座波罗教塔，是由三支钻石棒（Pag）所支撑，
 * 开始时神在第一根棒上放置64个由上至下依由小至大排列的金盘（Disc），
 * 并命令僧侣将所有的金盘从第一根石棒移至第三根石棒，且搬运过程中遵守大盘子在小盘子之下的原则，
 * 若每日仅搬一个盘子，则当盘子全数搬运完毕之时，此塔将毁损，而也就是世界末日来临之时。
 *************************************************************/

#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, string &A, string &B, string &C) {
    if (n == 1) {
        cout << "Move sheet" << n << " from " << A << " to " << C << endl;
    } else {
        hanoi(n - 1, A, C, B);
        cout << "Move sheet" << n << " from " << A << " to " << C << endl;
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    int n = 0;
    cout << "Please input number of sheet:" << endl;
    cin >> n;
    string sheetA = "A";
    string sheetB = "B";
    string sheetC = "C";
    hanoi(n, sheetA, sheetB, sheetC);

    return 0;
}
