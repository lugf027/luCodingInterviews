/*************************************************************
 * Name     : 03_lengthOfLongestSubstring
 * Title    : 
 * Author   : lugf027 17:15 2021/3/14.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace lengthOfLongestSubstring {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0;
            int rPos = -1;
            unordered_set<char> occurredChar;

            for(int i=0; i<s.size(); ++i){
                if(i!=0){
                    occurredChar.erase(s[i-1]);
                }
                while(rPos+1 < (int)s.size() && !occurredChar.count(s[rPos+1])){
                    occurredChar.insert(s[rPos+1]);
                    ++rPos;
                }
                res = max(res, rPos-i+1);
            }
            return res;
        }
    };
}
