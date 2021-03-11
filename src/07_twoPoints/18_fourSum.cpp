/*************************************************************
 * Name     : 18_fourSum
 * Title    : 
 * Author   : lugf027 14:30 2021/3/7.
 * Describe : 
 *************************************************************/

#include "util.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i+1 && nums[j] == nums[j - 1]) continue;

                int start = j + 1;
                int end = (int)nums.size() - 1;
                while (start < end) {
                    if (nums[i] + nums[j] + nums[start] + nums[end] > target) {
                        --end;
                    } else if (nums[i] + nums[j] + nums[start] + nums[end] < target) {
                        ++start;
                    } else {
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});
                        ++start;
                        --end;

                        while (start < end && nums[start] == nums[start - 1]) ++start;
                        while (start < end && end < nums.size() && nums[end] == nums[end + 1]) --end;
                    }
                }

            }
        }

        return res;
    }
};
