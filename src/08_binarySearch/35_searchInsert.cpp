/*************************************************************
 * Name     : 35_searchInsert
 * Title    : 
 * Author   : lugf027 11:02 2021/3/13.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace searchInsert {
    class Solution {
    public:
        int searchInsert(vector<int> &nums, int target) {
            int left = 0, right = (int) nums.size() - 1;

            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };
}



