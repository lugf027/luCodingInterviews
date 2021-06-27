/*************************************************************
 * Name     : 33_search
 * Title    : 
 * Author   : lugf027 15:59 2021/3/22.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace search {
    class Solution {
    public:
        int search(vector<int> &nums, int target) {
            int left = 0, right = nums.size() - 1;


            while (left <= right) {
                int mid = ((right - left) >> 1) + left;

                if (nums[mid] == target) return target;
                if (nums[mid] > target) {
                    if (nums[left] <= target && nums[right] < target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if (nums[left] > target && nums[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
            return -1;

        }
    };
}
