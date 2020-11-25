/********************************************
* Sort.h                              *
* Created by lugf027 on 2020/11/25.            *
* Github: https://github.com/lugf027        *
*********************************************/

#ifndef CODINGINTERVIEWS_SORT_H
#define CODINGINTERVIEWS_SORT_H


class Sort {

public:
    /// 从头到尾扫描序列,交换相邻的元素,让大的放在后面。接着从当前最大之外剩下的元素中继续这样交换
    static void bubbleIterative(int* arr, unsigned int n);

    static void bubbleRecursive(int* arr, unsigned int n);
    /// 若一次扫描中没有任何交换，则当前元素序列已然有序
    static void bubbleIterativeImprove(int* arr, unsigned int n);

    static void bubbleRecursiveImprove(int* arr, unsigned int n);
    /// 从头到尾扫描序列，找出最小元素和第一个元素交换。接着从第一个外剩下的元素中继续这样选择和交换
    static void selectIterative(int* arr, unsigned int n);
    ///
    static void selectRecursive(int* arr, unsigned int n);
    /// 一趟把最小值和最大值都选出来。最小值放到左边；最大值放到右边。
    static void selectIterativeImprove(int* arr, unsigned int n);

    static void selectRecursiveImprove(int* arr, unsigned int n);

private:
    inline static void swapInt(int &num1, int &num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
};


#endif //CODINGINTERVIEWS_SORT_H
