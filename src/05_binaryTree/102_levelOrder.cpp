/*************************************************************
 * Name     : 102_levelOrder
 * Title    : 102. 二叉树的层序遍历
 * Author   : lugf027 14:10 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace levelOrder {
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> res;
            if (!root) return res;
            queue<TreeNode *> treeQueue;
            treeQueue.emplace(root);

            while (!treeQueue.empty()) {
                vector<int> tmpValues;
                int levelNum = treeQueue.size();
                for (int i = 0; i < levelNum; ++i) {
                    TreeNode *treeTmp = treeQueue.front();
                    treeQueue.pop();
                    tmpValues.push_back(treeTmp->val);
                    if (treeTmp->left) treeQueue.push(treeTmp->left);
                    if (treeTmp->right) treeQueue.push(treeTmp->right);
                }
                res.push_back(tmpValues);
            }

            return res;
        }
    };
}
