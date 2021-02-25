/*************************************************************
 * Name     : 1021_removeOuterParentheses
 * Title    : 1021. 删除最外层的括号
 * Author   : lugf027 16:10 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace removeOuterParentheses{

    class Solution {
    public:
        string removeOuterParentheses(string S) {
//            assert(!S.empty());
            string res;
            int count = 0;
            for (const auto& ch : S) {
                if (ch == '(' && count++ > 0) {
                    res.push_back(ch);
                }
                if (ch == ')' && count-- > 1) {
                    res.push_back(ch);
                }
            }
            return res;
        }
    };


}
