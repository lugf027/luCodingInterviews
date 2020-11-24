/********************************************
* isNumber.cpp                              *
* Created by lugf027 on 2020/10/19.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 20. 表示数值的字符串
/// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
/// 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
/// 但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。


#include <string>

using namespace std;

namespace isNumber {

    class Solution {
    public:
        bool isNumber(string s) {
            if (s.empty()) return false;

            int len = s.length() - 1;
            while (s[len] == ' ')
                --len;
            if (len == -1) return false;

            bool hasNumber = false;
            bool canBePos = true;
            bool canBeDot = true;
            bool canBeE = false;

            for (char ch: s) {
                if (ch == ' ') continue;


            }


            for (int i = 0; i < len; ++i) {
                if (s[i] == ' ')
                    continue;

                if (canBePos) {
                    canBePos = false;
                    if (s[i] == '+' || s[i] == '-') {
                        if (i == len - 1) return false;
                        continue;
                    }
                    if (s[i] >= '0' && s[i] <= '0' + 9)
                        continue;
                    return false;
                }

                if (s[i] >= '0' && s[i] <= '0' + 9)
                    continue;

                if (s[i] == '.' && canBeDot) {
                    canBeDot = false;
                    continue;
                }

                if ((s[i] == 'e' || s[i] == 'E') && canBeE) {
                    if (i == len - 1) return false;
                    canBeE = false;
                    canBePos = true;
                    canBeDot = false;
                    continue;
                }


                int (* ptr1)[];

                return false;
            }
            return true;
        }
    };

    /**
     * codingInterviews
     */
    class Solution1 {
    public:
        bool isNumber(string s) {
            if (s.empty()) return false;
            const char* str = s.c_str();
            bool numeric = scanInteger(&str);

            while (*str == ' ')
                ++str;

            if (*str == '.') {
                ++str;
                // 因为小数点后面或者前面之一可以为空（无数字）
                numeric = scanUnsignedInteger(&str) || numeric;
            }

            if (*str == 'e' || *str == 'E') {
                ++str;
                numeric = numeric && scanInteger(&str);
            }

            while (*str == ' ')
                ++str;

            return numeric && *str == '\0';
        }

    private:
        bool scanUnsignedInteger(const char** str) {
            const char* before = *str;
            while (**str != '\0' && **str >= '0' && **str <= '9')
                ++(*str);

            return *str > before;
        }

        bool scanInteger(const char** str) {
            if (**str == '+' || **str == '-')
                ++(*str);
            return scanUnsignedInteger(str);
        }
    };
}


#include <unordered_map>

namespace isNumberLeetCode {
    class Solution {
    public:
        enum State {
            STATE_INITIAL,
            STATE_INT_SIGN,
            STATE_INTEGER,
            STATE_POINT,
            STATE_POINT_WITHOUT_INT,
            STATE_FRACTION,
            STATE_EXP,
            STATE_EXP_SIGN,
            STATE_EXP_NUMBER,
            STATE_END,
        };

        enum CharType {
            CHAR_NUMBER,
            CHAR_EXP,
            CHAR_POINT,
            CHAR_SIGN,
            CHAR_SPACE,
            CHAR_ILLEGAL,
        };

        CharType toCharType(char ch) {
            if (ch >= '0' && ch <= '9') {
                return CHAR_NUMBER;
            }
            else if (ch == 'e' || ch == 'E') {
                return CHAR_EXP;
            }
            else if (ch == '.') {
                return CHAR_POINT;
            }
            else if (ch == '+' || ch == '-') {
                return CHAR_SIGN;
            }
            else if (ch == ' ') {
                return CHAR_SPACE;
            }
            else {
                return CHAR_ILLEGAL;
            }
        }

        bool isNumber(string s) {
            unordered_map <State, unordered_map<CharType, State>> transfer{
                    {
                            STATE_INITIAL,           {
                                                             {CHAR_SPACE,  STATE_INITIAL},
                                                             {CHAR_NUMBER, STATE_INTEGER},
                                                             {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                                             {CHAR_SIGN,  STATE_INT_SIGN},
                                                     }
                    },

                    {
                            STATE_INT_SIGN,          {
                                                             {CHAR_NUMBER, STATE_INTEGER},
                                                             {CHAR_POINT,  STATE_POINT_WITHOUT_INT},
                                                     }
                    },

                    {
                            STATE_INTEGER,           {
                                                             {CHAR_NUMBER, STATE_INTEGER},
                                                             {CHAR_EXP,    STATE_EXP},
                                                             {CHAR_POINT, STATE_POINT},
                                                             {CHAR_SPACE, STATE_END},
                                                     }
                    },

                    {
                            STATE_POINT,             {
                                                             {CHAR_NUMBER, STATE_FRACTION},
                                                             {CHAR_EXP,    STATE_EXP},
                                                             {CHAR_SPACE, STATE_END},
                                                     }
                    },

                    {
                            STATE_POINT_WITHOUT_INT, {
                                                             {CHAR_NUMBER, STATE_FRACTION},
                                                     }
                    },

                    {
                            STATE_FRACTION,
                                                     {
                                                             {CHAR_NUMBER, STATE_FRACTION},
                                                             {CHAR_EXP,    STATE_EXP},
                                                             {CHAR_SPACE, STATE_END},
                                                     }
                    },

                    {
                            STATE_EXP,
                                                     {
                                                             {CHAR_NUMBER, STATE_EXP_NUMBER},
                                                             {CHAR_SIGN,   STATE_EXP_SIGN},
                                                     }
                    },

                    {
                            STATE_EXP_SIGN,          {
                                                             {CHAR_NUMBER, STATE_EXP_NUMBER},
                                                     }
                    },

                    {
                            STATE_EXP_NUMBER,        {
                                                             {CHAR_NUMBER, STATE_EXP_NUMBER},
                                                             {CHAR_SPACE,  STATE_END},
                                                     }
                    },

                    {
                            STATE_END,               {
                                                             {CHAR_SPACE,  STATE_END},
                                                     }
                    }
            };

            int len = s.length();
            State st = STATE_INITIAL;

            for (int i = 0; i < len; i++) {
                CharType typ = toCharType(s[i]);
                if (transfer[st].find(typ) == transfer[st].end()) {
                    return false;
                }
                else {
                    st = transfer[st][typ];
                }
            }
            return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER ||
                   st == STATE_END;
        }
    };
}
