/*************************************************************
 * Name     : 669_trimBST
 * Title    : 669. 修剪二叉搜索树
 * Author   : lugf027 17:59 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace trimBST {
    class Solution {
    public:
        TreeNode *trimBST(TreeNode *root, int low, int high) {
            if (root == nullptr) return root;
            if (root->val > high) return trimBST(root->left, low, high);
            if (root->val < low) return trimBST(root->right, low, high);

            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    };

    class Solution1 {
    public:
        TreeNode *trimBST(TreeNode *root, int low, int high) {
            if (root == nullptr) return nullptr;
            if (root->val > high) {
                root = root->left;
                root = trimBST(root, low, high);
            } else if (root->val < low) {
                root = root->right;
                root = trimBST(root, low, high);
            } else {
                //如果数字在区间内,就去裁剪左右子节点.
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
            }
            return root;
        }
    };
}
