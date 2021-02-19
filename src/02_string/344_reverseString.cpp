/*************************************************************
 * Name     : 344_reverseString
 * Title    : 344. 反转字符串
 * Author   : lugf027 9:52 2021/2/19.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace reverseString{
    class Solution {
    public:
        void reverseString(vector<char>& s) {
            char chTmp;
            int len = s.size();
            for(int i=0; i<len/2; ++i){
                chTmp = s[i];
                s[i]= s[len-i-1];
                s[len-i-1] = chTmp;
            }
        }
    };
}
