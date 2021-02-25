/*************************************************************
 * Name     : 202_isHappy
 * Title    : 
 * Author   : lugf027 11:33 2021/2/19.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace isHappy {

    /**
     * hash
     */
    class Solution {
    private:
        int getNext(int n) {
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            return sum;
        }

    public:
        bool isHappy(int n) {
            unordered_set<int> hashset;
            int sum;

            while (hashset.find(n) != hashset.end()) {
                if(n == 1) return true;
                hashset.insert(n);
                n = getNext(n);
            }
            return false;
        }
    };

    /**
     * 快慢指针
     * 不需要哈希集来检测循环。指针需要常数的额外空间
     */

}
