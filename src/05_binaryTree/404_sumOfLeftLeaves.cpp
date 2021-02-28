/*************************************************************
 * Name     : 404_sumOfLeftLeaves
 * Title    : 404. 左叶子之和
 * Author   : lugf027 14:21 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace sumOfLeftLeaves {
    /**
     * 深度
     */
    class Solution {
    private:
        void sumOfLeftLeavesAux(TreeNode *root, int &sum) {
            if (!root) return;
            if (root->left && !root->left->left && !root->left->right) sum += root->left->val;
            sumOfLeftLeavesAux(root->left, sum);
            sumOfLeftLeavesAux(root->right, sum);
        }

    public:
        int sumOfLeftLeaves(TreeNode *root) {
            int res = 0;
            sumOfLeftLeavesAux(root, res);
            return res;
        }
    };

    /**
     * 广度
     */
    class Solution1 {
    public:
        int sumOfLeftLeaves(TreeNode *root) {
            if (!root)
                return 0;

            queue<TreeNode *> q;
            q.push(root);
            int ans = 0;
            while (!q.empty()) {
                TreeNode *nodeTmp = q.front();
                q.pop();
                if (nodeTmp->left && !nodeTmp->left->left && !nodeTmp->left->right) {
                    ans += nodeTmp->left->val;
                } else if (nodeTmp->left ){
                    q.push(nodeTmp->left);
                }

                if (nodeTmp->right) {
                    q.push(nodeTmp->right);
                }
            }
            return ans;
        }
    };

}