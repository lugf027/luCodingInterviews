/*************************************************************
 * Name     : 98_isValidBST
 * Title    : 
 * Author   : lugf027 17:31 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace isValidBST{
    class Solution {
    private:
        bool isValidBSTAux(TreeNode* root, long long lower, long long upper) {
            if(!root) return true;
            if(root->val <=lower || root->val >= upper) return false;


            return isValidBSTAux(root->left, lower, root->val) && isValidBSTAux(root->right, root->val, upper);
        }
    public:
        bool isValidBSTAux(TreeNode* root) {
            return isValidBSTAux(root, LONG_MIN, LONG_MAX);
        }
    };
}
