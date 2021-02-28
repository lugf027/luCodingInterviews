/*************************************************************
 * Name     : 700_searchBST
 * Title    : 700. 二叉搜索树中的搜索
 * Author   : lugf027 17:26 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace searchBST{
    class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            while (root){
                if(root->val == val){
                    return root;
                }else if(root->val > val){
                    root = root->left;
                }else{
                    root = root->right;
                }
            }
            return nullptr;
        }
    };
}
