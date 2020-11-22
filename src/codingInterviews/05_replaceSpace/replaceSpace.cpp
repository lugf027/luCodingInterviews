/********************************************
* replaceSpace.cpp                              *
* Created by lugf027 on 2020/10/12.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <string>

using namespace std;

/// 面试题5：替换空格
/// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are haxppy.”，
/// 则输出“We%20are%20happy.”。

namespace replaceSpace {

    class Solution {
    public:
        string replaceSpace(string s) {
            string sRet;
            for (int i = 0; i < s.size(); ++i) {
                if (s.at(i) != ' ') {
                    sRet.push_back(s.at(i));
                }
                else {
                    sRet.push_back('%');
                    sRet.push_back('2');
                    sRet.push_back('0');
                }
            }
            return sRet;
        }
    };

    class StrTest {
    public:
        static int test() {
            char str1[] = "hello world";
            char str2[] = "hello world";

            char* str3 = "hello world";
            char* str4 = "hello world";

            printf("str1 addr:%p\nstr2 addr:%p\nstr3 addr:%p\nstr4 addr:%p\n", str1, str2, str3, str4);

            ///str1和str2是两个字符串数组，我们会为它们分配两个长度为12字节
            //的空间，并把"hello world"的内容分别复制到数组中去。这是两个初始地址
            //不同的数组，因此strl和str2的值也不相同，所以输出的第一- 行是"strl and
            //str2 are not same"。
            //str3和str4是两个指针，我们无须为它们分配内存以存储字符串的内容，
            //而只需要把它们指向"hello world" 在内存中的地址就可以了。由于"hello
            //world"是常量字符串，它在内存中只有一个拷贝，因此str3和str4指向的是
            //同一个地址。所以比较str3 和str4的值得到的结果是相同的，输出的第二
            //行是"str3 and str4 are same"。
            return 0;
        }
    };
}


