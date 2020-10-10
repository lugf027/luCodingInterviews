/********************************************
* AssignmentOperator.h                              *
* Created by lugf027 on 2020/10/10.            *
* Github: https://github.com/lugf027        *
*********************************************/

#ifndef CODINGINTERVIEWS_ASSIGNMENTOPERATOR_H
#define CODINGINTERVIEWS_ASSIGNMENTOPERATOR_H

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

    /// 新增测试到此文件
    static void Test1();
    static void Test2();
    static void Test3();

private:
    char* m_pData;
};


#endif //CODINGINTERVIEWS_ASSIGNMENTOPERATOR_H
