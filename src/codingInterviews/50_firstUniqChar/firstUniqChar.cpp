/********************************************
* firstUniqChar.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/


/// 剑指 Offer 50. 第一个只出现一次的字符
/// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

#include <string>
#include <unordered_map>

using namespace std;

namespace firstUniqChar {

    /**
     * unordered_map
     */
    class Solution {
    public:
        char firstUniqChar(string s) {
            unordered_map<char, int> count;
            for (int i = 0; i < 26; ++i) {
                count['a' + i] = 0;
            }
            for (char ch : s) {
                count[ch]++;
            }
            for (char ch : s) {
                if (count[ch] == 1)
                    return ch;
            }
            return ' ';
        }
    };

}

