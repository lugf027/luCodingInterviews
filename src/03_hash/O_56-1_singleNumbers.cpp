/*************************************************************
 * Name     : O_56
 * Title    : 剑指 Offer 56 - I. 数组中数字出现的次数
 * Author   : lugf027 14:49 2021/2/25.
 * Describe :
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 *************************************************************/

#include "util.h"

namespace singleNumbers {
    /**
     * 快排
     */
    class Solution {
    public:
        vector<int> singleNumbers(vector<int> &nums) {
            vector<int> res;

            sort(nums.begin(), nums.end());
            int i = 0;
            while (i < nums.size()) {
                if (i < nums.size() - 1 && nums[i] == nums[i + 1])
                    i += 2;
                else {
                    res.push_back(nums[i]);
                    ++i;
                }
            }

            return res;
        }
    };

    /**
     * hash
     */
    class Solution1 {
    public:
        vector<int> singleNumbers(vector<int>& nums) {
            vector<int> res;
            unordered_map<int, int> countNums;
            for(auto n:nums){
                countNums[n]++;
            }
            for(auto num_times:countNums){
                if(num_times.second == 1) res.push_back(num_times.first);
            }
            return res;
        }
    };
}
