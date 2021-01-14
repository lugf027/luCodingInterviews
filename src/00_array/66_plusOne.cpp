/*************************************************************
 * Name     : 66_plusOne
 * Title    : 66. 加一
 * Author   : lugf027 1:44 PM 1/11/2021.
 * Describe :
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 *************************************************************/

#include "util.h"

namespace plusOne{


    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            for (int i = digits.size() - 1; i >= 0; --i) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    return digits;
                }
            }
            vector<int> res(digits.size() + 1);
            res[0] = 1;
            digits.clear();
            digits = res;
            return digits;

        }
    };

}
