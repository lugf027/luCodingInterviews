/*************************************************************
 * Name     : 46_permute
 * Title    : 全排列
 * Author   : lugf027 15:07 2021/3/17.
 * Describe :
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 *************************************************************/

#include <vector>

using namespace std;

namespace permute {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int> &nums) {
            if (nums.empty()) return {};

            vector<vector<int>> res(1, vector<int>(1, nums[0]));

            for (int i = 1; i < nums.size(); ++i) {
                vector<vector<int>> tmp;
                for (vector<int> ahead: res) {
                    ahead.push_back(nums[i]);
                    tmp.push_back(ahead);
                    for (int j = (int) ahead.size() - 2; i >= 0; --i) {
                        swap(ahead[j], ahead[j + 1]);
                        tmp.push_back(ahead);
                    }
                }
                res = tmp;
            }

            return res;
        }
    };
}
