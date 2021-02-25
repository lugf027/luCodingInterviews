/*************************************************************
 * Name     : 20_isValid
 * Title    : 20. 有效的括号
 * Author   : lugf027 15:13 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace isValid {
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> brackets;
//            for(char ch:s){
//               if(ch == '(' || ch == '[' || ch == '}'){
//                    brackets.push(ch);
//                }
//               else if(ch == ')' && brackets.top() == '(') brackets.pop();
//               else if(ch == ']' && brackets.top() == '[') brackets.pop();
//               else if(ch == '}' && brackets.top() == '{') brackets.pop(); // ch == '}' 会报错
//               else return false;
//            }

            for (char c:s) {
                if (!brackets.empty()) {
                    char t = brackets.top();
                    if (t == '(' && c == ')' || t == '[' && c == ']' || t == '{' && c == '}') {
                        brackets.pop();
                        continue;
                    }
                }
                brackets.push(c);
            }
            return brackets.empty();
        }
    };
}
