/********************************************
* isSymmetric.cpp                              *
* Created by lugf027 on 2020/11/24.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 28. 对称的二叉树
/// 请实现一个函数，用来判断一棵二叉树是不是对称的。如
/// 果一棵二叉树和它的镜像一样，那么它是对称的。

namespace isSymmetric {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (!root || (!root->left && !root->right)) return true;
            return isSymmetricAux(root->left, root->right);
        }

        bool isSymmetricAux(TreeNode* left, TreeNode* right) {
            if (!left && !right) return true;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            return isSymmetricAux(left->left, right->right) && isSymmetricAux(left->right, right->left);
        }
    };
}
