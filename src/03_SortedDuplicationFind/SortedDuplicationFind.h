/********************************************
* SortedDuplicationFind.h                              *
* Created by lugf027 on 2020/10/10.            *
* Github: https://github.com/lugf027        *
*********************************************/

#ifndef CODINGINTERVIEWS_SORTEDDUPLICATIONFIND_H
#define CODINGINTERVIEWS_SORTEDDUPLICATIONFIND_H

//面试题3:二维数组中的查找
//题目:在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的
//个二维数组和一个整数，判断数组中是否含有该整数。

class SortedDuplicationFind {
public:
    static bool find(int* matrix, int rows, int columns, int number);

    static void Test();
};


#endif //CODINGINTERVIEWS_SORTEDDUPLICATIONFIND_H
