/*************************************************************
 * Name     : 1047_removeDuplicates
 * Title    : 
 * Author   : lugf027 19:37 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace removeDuplicates {
    /**
     * stack + stack to str
     */
    class Solution {
    public:
        string removeDuplicates(string S) {
            stack<char> strStack;
            for (char ch: S) {
                if (strStack.empty() || strStack.top() != ch) {
                    strStack.push(ch);
                } else {
                    strStack.pop();
                }
            }

            string strRes(strStack.size() + 1, '\0');
            for (int i = strStack.size(); i >= 0; --i) {
                strRes[i] = strStack.top();
                strStack.pop();
            }

            return strRes;
        }
    };

    /**
     * string as stack
     */
    class Solution1 {
    public:
        string removeDuplicates(string S) {
            string strRes;
            for (char ch: S) {
                if (strRes.empty() || strRes.back() != ch) {
                    strRes += ch;
                } else {
                    strRes.erase(strRes.begin()+strRes.size()-1);
                }
            }
            return strRes;
        }
    };
}
