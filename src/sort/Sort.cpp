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


