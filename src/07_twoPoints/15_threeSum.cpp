/*************************************************************
 * Name     : 15_threeSum
 * Title    : 
 * Author   : lugf027 12:18 2021/3/7.
 * Describe : 
 *************************************************************/
#include "util.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] > -nums[i])
                    --end;
                else if (nums[start] + nums[end] < -nums[i])
                    ++start;
                else {
                    res.push_back({nums[i], nums[start], nums[end]});
                    ++start;
                    --end;

                    while (start <end && nums[start] == nums[start - 1])
                        ++start;
                    while (end > start && nums[end] == nums[end + 1])
                        --end;
                }
            }
        }
        return res;
    }
};
