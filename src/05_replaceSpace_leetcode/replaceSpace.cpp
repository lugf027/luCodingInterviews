/********************************************
* replaceSpace.cpp                              *
* Created by lugf027 on 2020/10/12.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <string>

using namespace std;

/// 面试题5：替换空格
/// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
/// 则输出“We%20are%20happy.”。

class Solution {
public:
    string replaceSpace(string s) {
        string sRet;
        for(int i=0; i<s.size();++i){
            if(s.at(i) != ' '){
                sRet.push_back(s.at(i));
            }else{
                sRet.push_back('%');
                sRet.push_back('2');
                sRet.push_back('0');
            }
        }
        return sRet;
    }
};
