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

    /// 从前至后依次构建有序序列. 对于未排序的新元素，在之前有序序列中从后往前扫描找到相应位置并插入
    // 插入排序不足：1、寻找插入位置；2、移动元素。
    // 优化：1、二分查找插入位置；2、携带多个元素；3、数据链表化；4、希尔排序
    static void insertSort(int* arr, unsigned int n);

    /// 将待排序数组依次按间隔分为多个跳跃的组，对每个组进行插入排序，让数列整体更有序；直至间隔为零那次插入排序使整体有序
    // 希尔排序核心：1、查找次数减少；2、移动元素的次数减少
    // 希尔排序 ShellSort 是指希尔提出了一种冲破二次时间屏障的算法，
    // 希尔增量是希尔排序中希尔给出的增量序列 ht = N / 2, h[k+1] = h[k] / 2，即{N/2, (N / 2)/2, ..., 1}
    static void shellSort(int* arr, unsigned int n);


private:
    inline static void swapInt(int &num1, int &num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    static void shellSortAux(int* arr, unsigned int n, int step);

};


#endif //CODINGINTERVIEWS_SORT_H
