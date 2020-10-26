/********************************************
* isMatch.cpp                              *
* Created by lugf027 on 2020/10/19.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 19. 正则表达式匹配
/// 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
/// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
/// 在本题中，匹配是指字符串的所有字符匹配整个模式。
/// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchAux(s.c_str(), p.c_str(), 0, 0);
    }

private:
    /**
     * 这里如果不用 const char * 引用传递，而是 string 值传递的话，会超时
     * @param s
     * @param p
     * @param sStep
     * @param pStep
     * @return
     */
    bool isMatchAux(const char *s, const char *p, int sStep, int pStep) {
        if (s[sStep] == '\0' && p[pStep] == '\0') {
            return true;
        }

        if (s[sStep] != '\0' && p[pStep] == '\0') {
            return false;
        }

        if (p[pStep + 1] == '*') {
            if (p[pStep] == s[sStep] || (p[pStep] == '.' && s[sStep] != '\0')) {
                return isMatchAux(s, p, sStep + 1, pStep + 2)  // move on the next state
                       || isMatchAux(s, p, sStep + 1, pStep)    // stay on the current state
                       || isMatchAux(s, p, sStep, pStep + 2);    // ignore a '*'
            } else {
                return isMatchAux(s, p, sStep, pStep + 2);    // ignore a '*';
            }
        }

        if (s[sStep] == p[pStep] || (p[pStep] == '.' && s[sStep] != '\0')) {
            return isMatchAux(s, p, sStep + 1, pStep + 1);
        }

        return false;
    }
};