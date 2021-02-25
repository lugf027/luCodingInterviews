/*************************************************************
 * Name     : 1_twoSum
 * Title    : 1. 两数之和
 * Author   : lugf027 11:08 2021/2/19.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace twoSum {
    class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            unordered_map<int, int> hashtable;
            for (int i = 0; i < nums.size(); ++i) {
                auto it = hashtable.find(target - nums[i]);
                if (it != hashtable.end())
                    return {it->second, i};

                hashtable[nums[i]] = i;
            }
            return {};
        }
    };
}
