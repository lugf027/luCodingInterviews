/*************************************************************
 * Name     : 235_lowestCommonAncestor
 * Title    : 
 * Author   : lugf027 17:59 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace lowestCommonAncestor {
    class Solution {
    private:
        vector<TreeNode*>  getPath(TreeNode* root, TreeNode* target) {
            vector<TreeNode*> res;
            while (root!=target){
                res.push_back(root);
                if(root->val > target->val && root->left){
                    root = root->left;
                }else if(root->val < target->val && root->right){
                    root = root->right;
                }
            }
            res.push_back(root);
            return res;
        }
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
            vector<TreeNode*> pathP = getPath(root, p);
            vector<TreeNode*> pathQ = getPath(root, q);

            TreeNode* res;
            for (int i = 0; i < pathP.size() && i < pathQ.size(); ++i) {
                if (pathP[i] == pathQ[i]) {
                    res = pathP[i];
                }
                else {
                    break;
                }
            }
            return res;
        }
    };

    class Solution1 {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while (true) {
                if (p->val < root->val && q->val < root->val) {
                    root = root->left;
                }
                else if (p->val > root->val && q->val > root->val) {
                    root = root->right;
                }
                else {
                    break;
                }
            }
            return root;
        }
    };
}
