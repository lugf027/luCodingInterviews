/********************************************
* AssignmentOperator.cpp                              *
* Created by lugf027 on 2020/10/10.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <cstdlib>
#include "AssignmentOperator.h"

CMyString::CMyString(char *pData) {
    if (pData != nullptr) {
        m_pData = (char *) std::malloc(sizeof(pData) + 1);
        strcpy(m_pData, pData);
    } else {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
}

CMyString::CMyString(const CMyString &str) {
    m_pData = (char *) std::malloc(sizeof(str.m_pData) + 1);
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() {
    delete[] m_pData;
}

CMyString &CMyString::operator=(const CMyString &str) {
//    if (this == &str) {
//        return *this;
//    }
//    delete[]m_pData;
//    m_pData = nullptr;
//    m_pData = (char *) std::malloc(sizeof(str.m_pData) + 1);
//    strcpy(m_pData, str.m_pData);

    // 防止内存不足时，破坏this->m_pData
    if(this != &str){
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }

    return *this;
}

void CMyString::Print() {
    printf("%s", m_pData);
//    int len = strlen(m_pData);
//    for (int i = 0; i < len; i++) {
//        printf("%c", m_pData[i]);
//    }
}

void CMyString::Test1() {
    printf("Test1 begins:\n");

    char* text =  (char *)"Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

/**
 * 赋值给自己
 */
void CMyString::Test2() {
    printf("Test2 begins:\n");

    char* text = (char *)"Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

/**
 * 连续赋值
 */
void CMyString::Test3() {
    printf("Test3 begins:\n");

    char* text = (char *)"Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}
