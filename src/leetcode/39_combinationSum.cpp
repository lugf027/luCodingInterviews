/*************************************************************
 * Name     : 39_combinationSum
 * Title    : 39 组合总和
 * Author   : lugf027 9:28 2021/3/17.
 * Describe : 
 *************************************************************/

#include <vector>

using namespace std;

namespace combinationSum {
    class Solution {
    private:
        void dfs(vector<int> &candidates, int target, vector<vector<int>> &res,
                 vector<int> &combine, int index) {
            if (index == candidates.size()) return;

            if (target == 0) {
                res.emplace_back(combine);
                return;
            }

            dfs(candidates, target, res, combine, index + 1);

            if (target - candidates[index] >= 0) {
                combine.emplace_back(candidates[index]);
                dfs(candidates, target - candidates[index], res, combine, index);
                combine.pop_back();
            }

        }

    public:
        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
            vector<vector<int>> res;
            vector<int> combine;

            dfs(candidates, target, res, combine, 0);

            return res;
        }
    };
}
