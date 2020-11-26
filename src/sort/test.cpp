/********************************************
* test.cpp                              *
* Created by lugf027 on 2020/11/25.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "Sort.h"

/// the sortFunc's pointer
typedef void (* SortFunc)(int*, unsigned int);

typedef void (* SortFunc_intLen)(int*, int);

/// test a Sort Function
inline void testASort(SortFunc sortFunc, const char* sortType);

inline void testASort(SortFunc_intLen sortFunc, const char* sortType);

/// malloc & gen IntArr
int* arrGen(int* arr, unsigned int n);

/// print & free IntArr
void arrPrint(int* arr, unsigned int n);

int main(int argc, char* argv[]) {

//    testASort(&Sort::bubbleRecursive, "BubbleSort (Recursive)");
//    testASort(&Sort::bubbleIterative, "BubbleSort (Iterative)");
//    testASort(&Sort::bubbleRecursiveImprove, "BubbleSortImprove (Recursive)");
//    testASort(&Sort::bubbleIterativeImprove, "BubbleSortImprove (Iterative)");
//
//    testASort(&Sort::selectIterative, "SelectSort (Iterative)");
//    testASort(&Sort::selectRecursive, "SelectSort (Recursive)");
//    testASort(&Sort::selectIterativeImprove, "SelectSortImprove (Iterative)");
//    testASort(&Sort::selectRecursiveImprove, "SelectSortImprove (Recursive)");

//    testASort(&Sort::insertSort, "InsertSort");
//    testASort(&Sort::shellSort, "ShellSort");

    testASort(&Sort::quickSort, "QuickSort");

    testASort(&Sort::mergeSortRecursive, "mergeSortRecursive");
    testASort(&Sort::mergeSortIterative, "mergeSortIterative");
    return 0;
}

inline void testASort(SortFunc sortFunc, const char* sortType) {
//    std::default_random_engine randomEngine;
//    randomEngine.seed(time(NULL)+randomEngine());
//    unsigned int n = randomEngine() % 20 + 1;

//    std::uniform_int_distribution<unsigned> uniformIntDistribution(0, 9);
//    unsigned int n = uniformIntDistribution(randomEngine) % 20 + 1;

//    unsigned int n = rand() % 20 + 1;
    unsigned int n = 15;
    static int* arr = nullptr;

    printf("\033[;36m%s\033[0m\n", sortType);
    arr = arrGen(arr, n);
    sortFunc(arr, n);
    arrPrint(arr, n);
}

inline void testASort(SortFunc_intLen sortFunc, const char* sortType) {
    unsigned int n = 15;
    static int* arr = nullptr;

    printf("\033[;36m%s\033[0m\n", sortType);
    arr = arrGen(arr, n);
    sortFunc(arr, n);
    arrPrint(arr, n);
}

int* arrGen(int* arr, unsigned int n) {
    arr = (int*) malloc(sizeof(int) * n);
    printf("New Arr: ");
    for (int i = 0; i < n; ++i) {
        srand((unsigned) time(NULL) + rand());
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return arr;
}

void arrPrint(int* arr, unsigned int n) {
    printf("SortArr: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    free(arr);
}

