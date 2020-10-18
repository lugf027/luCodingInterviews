/********************************************
* backspaceCompare.cpp                              *
* Created by lugf027 on 2020/10/19.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 844. 比较含退格的字符串
/// 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
/// 注意：如果对空文本输入退格字符，文本继续为空。

#include <string>

using namespace std;

/**
 * 双指针
 */
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int backspaceS = 0, backspaceT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    backspaceS++, i--;
                } else if (backspaceS > 0) {
                    backspaceS--, i--;
                } else {
                    break;
                }
            }

            while (j >= 0) {
                if (T[j] == '#') {
                    backspaceT++, j--;
                } else if (backspaceT > 0) {
                    backspaceT--, j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }

            i--, j--;
        }
        return true;
    }
};

/**
 * 栈
 */
class Solution1 {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};
