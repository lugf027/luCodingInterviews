/*************************************************************
 * Name     : O_03_findRepeatNumber
 * Title    : 剑指 Offer 03. 数组中重复的数字
 * Author   : lugf027 2:06 PM 1/11/2021.
 * Describe :
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
 * 请找出数组中任意一个重复的数字。
 *************************************************************/

#include "util.h"

namespace findRepeatNumber {

    /**
     * 位置规律
     */
    class Solution {
    public:
        int findRepeatNumber(vector<int> &nums) {
            for (int i = 0; i < nums.size();) {
                if (nums[i] != i) {
                    if (nums[i] != nums[nums[i]])
                        swap(nums[i], nums[nums[i]]);
                    else
                        return nums[i];
                } else {
                    ++i;
                }
            }
            return -1;
        }
    };


    /**
     * 快速排序
     */
    class Solution1 {
    public:
        int findRepeatNumber(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1;) {
                if (nums[i] == nums[++i]) {
                    return nums[i];
                }
            }
            return -1;
        }
    };

}
