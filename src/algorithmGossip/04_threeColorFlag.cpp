/*************************************************************
 * Name     : 03_threeColorFlag
 * Title    : 03 三色旗 荷兰国旗
 * Author   : lugf027 21:00 2021/1/17.
 * Describe :
 * 假设有一条绳子，上面有红、白、蓝三种颜色的旗子，起初绳子上的旗子颜色并没有顺序；
 * 您希望将之分类，并排列为蓝、白、红的顺序，要如何移动次数才会最少；
 * 注意您只能在绳子上进行这个动作，而且一次只能调换两个旗子。
 * 又：Leetcode 75. 颜色分类
 *************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

enum Flags {
    BLUE = 0,
    WHITE = 1,
    RED = 2,
};

void sortColorsByQuickSort(vector<char> &nums) {
    sort(nums.begin(), nums.end());
}

void sortColorsByPointers(vector<char> &nums) {
    int pBlue = 0;
    int pRed = (int)nums.size() - 1;
    int pMid = 0;

    while (pMid < pRed){
        if(nums[pMid] == BLUE){
            swap(nums[pMid], nums[pBlue]);
            ++pMid;
            ++pBlue;
        }else if(nums[pMid] == RED){
            swap(nums[pMid], nums[pRed]);
            --pRed;
        }else if(nums[pMid] == WHITE){
            ++pMid;
        }
    }
}
