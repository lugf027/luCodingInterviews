/*************************************************************
 * Name     : 34_searchRange
 * Title    : 
 * Author   : lugf027 12:50 2021/3/13.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace searchRange {
    class Solution {
    public:
        vector<int> searchRange(vector<int> &nums, int target) {
            if (nums.empty()) return {-1, -1};
            vector<int> res;

            int left = 0, right = (int) nums.size() - 1;
            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (target <= nums[mid]) {
                    right = mid - 1;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                }
            }
            if (left >= 0 && left < nums.size())
                res.push_back(nums[left] == target ? left : -1);
            else
                res.push_back(-1);

            left = 0, right = (int) nums.size() - 1;
            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (target >= nums[mid]) {
                    left = mid + 1;
                } else if (target < nums[mid]) {
                    right = mid - 1;
                }
            }
            if (right >= 0 && right < nums.size())
                res.push_back(nums[right] == target ? right : -1);
            else
                res.push_back(-1);

            return res;
        }
    };
}
