/*************************************************************
 * Name     : O_55
 * Title    : 剑指 Offer 55 - I. 二叉树的深度
 * Author   : lugf027 14:02 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace maxDepth {
    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (!root) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };

    /**
     * 层次遍历
     */
    class Solution1 {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            int depth = 0;
            queue<TreeNode*> treeQueue;
            treeQueue.push(root);
            while(!treeQueue.empty()) {
                int size = treeQueue.size();
                depth++; // 记录深度
                for (int i = 0; i < size; i++) {
                    TreeNode* node = treeQueue.front();
                    treeQueue.pop();
                    if (node->left) treeQueue.push(node->left);
                    if (node->right) treeQueue.push(node->right);
                }
            }
            return depth;
        }
    };
}
