/*************************************************************
 * Name     : O_56
 * Title    : 剑指 Offer 56 - II. 数组中数字出现的次数 II
 * Author   : lugf027 14:49 2021/2/25.
 * Describe :
 * 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
 * 请找出那个只出现一次的数字。
 *************************************************************/

#include "util.h"

namespace singleNumber {
    class Solution {
    public:
        int singleNumber(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            int i = 0;
            while (i < nums.size()) {
                if (i < nums.size() - 2 && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
                    i += 3;
                else
                    return nums[i];
            }
            return -1;
        }
    };

    class Solution1 {
    public:
        int singleNumber(vector<int> &nums) {
            unordered_map<int, int> countNums;
            for (auto n:nums) {
                countNums[n]++;
            }
            for (auto num_times:countNums) {
                if (num_times.second == 1) return num_times.first;
            }
            return -1;
        }
    };

}
