/*************************************************************
 * Name     : 1_twoSum
 * Title    : 1. 两数之和
 * Author   : lugf027 10:42 AM 1/11/2021.
 * Describe :
 * 给定一个整数数组 nums 和一个整数目标值 target，
 * 请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 你可以按任意顺序返回答案。
 *************************************************************/

#include "util.h"

namespace twoSum {

    class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            vector<int> res;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1;; ++j) {
                    if (j < nums.size()) {
                        if (nums[i] + nums[j] == target) {
                            res.push_back(i);
                            res.push_back(j);
                            return res;
                        }
                    } else {
                        break;
                    }
                }
            }
            return res;
        }
    };

}

