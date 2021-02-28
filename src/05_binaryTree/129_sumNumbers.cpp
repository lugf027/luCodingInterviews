/*************************************************************
 * Name     : 129_sumNumbers
 * Title    : 
 * Author   : lugf027 14:49 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace sumNumbers {
    class Solution {
    private:
        int dfs(TreeNode *root, int prevSum) {
            if (!root) return 0;

            int sum = prevSum * 10 + root->val;
            if (root->left == nullptr && root->right == nullptr) {
                return sum;
            } else {
                return dfs(root->left, sum) + dfs(root->right, sum);
            }
        }

    public:
        int sumNumbers(TreeNode *root) {
            return dfs(root, 0);
        }
    };


    class Solution1 {
    public:
        int sumNumbers(TreeNode *root) {
            if (root == nullptr)
                return 0;

            int sum = 0;
            queue<TreeNode *> treeQueue;
            queue<int> numQueue;
            treeQueue.push(root);
            numQueue.push(root->val);

            while (!treeQueue.empty()) {
                TreeNode *nodeTmp = treeQueue.front();
                int numTmp = numQueue.front();

                treeQueue.pop();
                numQueue.pop();

                if (!nodeTmp->left && !nodeTmp->right) {
                    sum += numTmp;
                } else {
                    if (nodeTmp->left) {
                        treeQueue.push(nodeTmp->left);
                        numQueue.push(nodeTmp->left->val + 10 * numTmp);
                    }
                    if (nodeTmp->right) {
                        treeQueue.push(nodeTmp->right);
                        numQueue.push(nodeTmp->right->val + 10 * numTmp);
                    }
                }

            }

            return sum;
        }
    };
}
