/********************************************
* Sort.cpp                              *
* Created by lugf027 on 2020/11/25.            *
* Github: https://github.com/lugf027        *
*********************************************/
#include <iostream>
#include "Sort.h"

void Sort::bubbleIterative(int* arr, unsigned int n) {
    // 打印函数名
    // printf("%s", __func__);
    if (n < 2) return;

    for (unsigned int i = n - 1; i > 0; --i) {
        for (unsigned int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort::bubbleRecursive(int* arr, unsigned int n) {
    if (n < 2) return;
    for (unsigned int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            int tmp = arr[i + 1];
            swapInt(arr[i], arr[i + 1]);
            arr[i] = tmp;
        }
    }
    bubbleRecursive(arr, n - 1);
}

void Sort::bubbleIterativeImprove(int* arr, unsigned int n) {
    if (n < 2) return;

    for (unsigned int i = n - 1; i > 0; --i) {
        int notSwap = 1;
        for (unsigned int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
                notSwap = 0;
            }
        }
        if (notSwap) return;
    }
}

void Sort::bubbleRecursiveImprove(int* arr, unsigned int n) {
    if (n < 2) return;
    int notSwap = 1;
    for (unsigned int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swapInt(arr[i], arr[i + 1]);
            notSwap = 0;
        }
    }
    if (notSwap) return;
    bubbleRecursiveImprove(arr, n - 1);
}

void Sort::selectIterative(int* arr, unsigned int n) {
    if (n < 2) return;
    for (int i = 0; i < n; ++i) {
        int minPos = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minPos]) minPos = j;
        }
        if (minPos != i) swapInt(arr[minPos], arr[i]);
    }
}

void Sort::selectRecursive(int* arr, unsigned int n) {
    if (n < 2) return;
    int minPos = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[minPos]) minPos = i;
    }
    if (minPos != 0) swapInt(arr[0], arr[minPos]);
    selectRecursive(arr + 1, n - 1);
}

/// 一趟把最小值和最大值都选出来。最小值放到左边；最大值放到右边。
void Sort::selectIterativeImprove(int* arr, unsigned int n) {
    if (n < 2) return;
    for (int i = 0; i < n; ++i, --n) {
        unsigned int minPos = i;
        unsigned int maxPos = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minPos]) minPos = j;
            if (arr[j] > arr[maxPos]) maxPos = j;
        }
        if (minPos != i) swapInt(arr[minPos], arr[i]);
        if (maxPos == i) swapInt(arr[n - 1], arr[minPos]);
        else if (maxPos != n - 1) swapInt(arr[maxPos], arr[n - 1]);
    }
}

void Sort::selectRecursiveImprove(int* arr, unsigned int n) {
    if (n < 2) return;
    unsigned int minPos = 0;
    unsigned int maxPos = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }
    if (minPos != 0) swapInt(arr[minPos], arr[0]);
    if (maxPos == 0) swapInt(arr[n - 1], arr[minPos]);
    else if (maxPos != n - 1) swapInt(arr[maxPos], arr[n - 1]);

    selectRecursiveImprove(arr + 1, n - 2);
}

void Sort::insertSort(int* arr, unsigned int n) {
    if (n < 2) return;
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] <= tmp) break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

void Sort::shellSort(int* arr, unsigned int n) {
    for (int i = n / 2; i > 0; i = i / 2) {
        // i can't be unsigned here for UNSIGNED_INT_MAX may be appear
        shellSortAux(arr, n, i);
    }
    shellSortAux(arr, n, 0);
}

/**
 * 希尔排序辅助函数，给各个组排序
 * @param  arr 待排序数组（整体）
 * @param    n 数组长度
 * @param step 分组间隔
 */
void Sort::shellSortAux(int* arr, unsigned int n, int step) {
    for (int groupI = 0; groupI < step; ++groupI) {
        for (int groupInnerI = groupI + step; groupInnerI < n; groupInnerI += step) {
            int tmp = arr[groupInnerI];
            int groupPreI = groupInnerI - step;
            for (; groupPreI >= 0; groupPreI -= step) {
                if (arr[groupPreI] < tmp) break;
                arr[groupPreI + step] = arr[groupPreI];
            }
            arr[groupPreI + step] = tmp;
        }
    }
    std::cout.width(7);
    std::cout << step << ": ";
    for (int printI = 0; printI < n; ++printI) {
        printf("%d ", arr[printI]);
    }
    printf("\n");
}

void Sort::quickSort(int* arr, int n) {
    if (n < 2) return;

    int tmp = arr[0];
    int iLeft = 0, iRight = n - 1;
    while (iLeft < iRight) {
        while (iLeft < iRight && arr[iRight] >= tmp)
            --iRight;
        if (iLeft < iRight)
            arr[iLeft++] = arr[iRight];

        while (iLeft < iRight && arr[iLeft] < tmp)
            ++iLeft;
        if (iLeft < iRight)
            arr[iRight--] = arr[iLeft];
    }

    arr[iLeft] = tmp;
    quickSort(arr, iLeft);
    quickSort(arr + iLeft + 1, n - iLeft - 1);
}

void Sort::mergeSortIterative(int* arr, int n) {
    if (n < 2) return;

    int* arrTmp = arr;
    int* arrSorted = (int*) malloc(n * sizeof(int));

    for (int iSeg = 1; iSeg < n; iSeg *= 2) {
        for (int iStart = 0; iStart < n; iStart = iStart + iSeg * 2) {
            int iLeft = iStart;
            int iMid = std::min(iStart + iSeg, n);
            int iRight = std::min(iStart + iSeg * 2, n);

            int i = iStart;
            int iStart1 = iLeft, iEnd1 = iMid;
            int iSTart2 = iMid, iEnd2 = iRight;

            while (iStart1 <= iEnd1 && iSTart2 <= iEnd2)
                arrSorted[i++] = arrTmp[iStart1] < arrTmp[iSTart2] ? arrTmp[iStart1++] : arrTmp[iSTart2++];

            while (iStart1 <= iEnd1) arrSorted[i++] = arrTmp[iStart1++];
            while (iSTart2 <= iEnd2) arrSorted[i++] = arrTmp[iSTart2++];
        }

        int* pTmp = arrTmp;
        arrTmp = arrSorted;
        arrSorted = pTmp;
    }

    if (arrTmp != arr) {
        memcpy(arr, arrTmp, n * sizeof(int));

        arrSorted = arrTmp;
    }
    //free(arrSorted);
}

void Sort::mergeSortRecursive(int* arr, int n) {
    if (n < 2) return;
    int arrTmp[n];
    mergeSortRecursiveAux(arr, arrTmp, 0, n - 1);
}

void Sort::mergeSortRecursiveAux(int* arr, int* arrTmp, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    int iStart1 = start, iEnd1 = mid;
    int iSTart2 = mid + 1, iEnd2 = end;

    mergeSortRecursiveAux(arr, arrTmp, iStart1, iEnd1);
    mergeSortRecursiveAux(arr, arrTmp, iSTart2, iEnd2);

    int i = start;
    while (iStart1 <= iEnd1 && iSTart2 <= iEnd2)
        arrTmp[i++] = arr[iStart1] < arr[iSTart2] ? arr[iStart1++] : arr[iSTart2++];

    while (iStart1 <= iEnd1) arrTmp[i++] = arr[iStart1++];
    while (iSTart2 <= iEnd2) arrTmp[i++] = arr[iSTart2++];

    memcpy(arr + start, arrTmp + start, (end - start + 1) * sizeof(int));
}

