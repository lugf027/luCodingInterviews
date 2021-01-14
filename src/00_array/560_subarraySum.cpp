/*************************************************************
 * Name     : 560_subarraySum
 * Title    : 560. 和为K的子数组
 * Author   : lugf027 3:27 PM 1/11/2021.
 * Describe :
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 *************************************************************/

#include "util.h"

namespace subarraySum {

    /**
     * 前缀和 + 哈希表优化
     */
    class Solution1 {
    public:
        int subarraySum(vector<int> &nums, int k) {
            int res = 0;
            unordered_map<int, int> mp;
            mp[0] = 1;

            int pre = 0;
            for (auto &v:nums) {
                pre += v;
                if (mp.find(pre - k) != mp.end())
                    res += mp[pre - k];
                ++mp[pre];
            }

            return res;
        }
    };

    /**
     * 暴力、超时
     */
    class Solution {
    public:
        int subarraySum(vector<int> &nums, int k) {
            int res = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int sum = nums[i];
                if (sum == k) ++res;
                for (int j = i + 1; j < nums.size(); ++j) {
                    sum += nums[j];
                    if (sum == k) ++res;
                }
            }
            return res;
        }

        int subarraySum1(vector<int> &nums, int k) {
            int count = 0;
            for (int start = 0; start < nums.size(); ++start) {
                int sum = 0;
                for (int end = start; end >= 0; --end) {
                    sum += nums[end];
                    if (sum == k) {
                        count++;
                    }
                }
            }
            return count;
        }
    };
}
