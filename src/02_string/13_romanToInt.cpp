/*************************************************************
 * Name     : 13_romanToInt
 * Title    : 13. 罗马数字转整数
 * Author   : lugf027 17:07 2021/1/20.
 * Describe :
 * 罗马数字包含以下七种字符: I 1， V 5， X 10， L 50，C 100，D 500 和 M 1000。
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 *************************************************************/

#include "util.h"

namespace romanToInt {

    class Solution0 {
    private:
        int getValue(char ch) {
            switch(ch) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        }

    public:
        int romanToInt(string s) {
            int res = 0;
            int num = 0;
            int preNum = 0;
            for(char ch: s){
                num = getValue(ch);
                if(num < preNum) res+=preNum;
                else res-=preNum;
                preNum = num;
            }
            res+=preNum;
            return res;
        }
    };

    /**
     * 常规常距
     */
    class Solution {
    public:
        int romanToInt(string s) {
            int res = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == 'M') res += 1000;
                if (s[i] == 'D') res += 500;
                if (s[i] == 'C') {
                    if (s[i + 1] == 'D') {
                        res += 400;
                        ++i;
                    } else if (s[i + 1] == 'M') {
                        res += 900;
                        ++i;
                    } else res += 100;
                }
                if (s[i] == 'L') res += 50;
                if (s[i] == 'X') {
                    if (s[i + 1] == 'L') {
                        res += 40;
                        ++i;
                    } else if (s[i + 1] == 'C') {
                        res += 90;
                        ++i;
                    } else res += 10;
                }
                if (s[i] == 'V') res += 5;
                if (s[i] == 'I') {
                    if (s[i + 1] == 'V') {
                        res += 4;
                        ++i;
                    } else if (s[i + 1] == 'X') {
                        res += 9;
                        ++i;
                    } else res += 1;
                }

            }
            return res;
        }
    };
}

