/*************************************************************
 * Name     : 209_minSubArrayLen
 * Title    : 
 * Author   : lugf027 15:07 2021/3/7.
 * Describe : 
 *************************************************************/

#include "util.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        if (nums.empty()) return 0;

        int res = INT_MAX;

        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= nums.size(); ++i) {
            int my_target = target + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), my_target);
            if(bound!=sums.end()){
                res = min(res, static_cast<int>((bound-sums.begin())-(i-1)));
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

