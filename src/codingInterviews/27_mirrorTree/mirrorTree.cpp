/********************************************
* mirrorTree.cpp                              *
* Created by lugf027 on 2020/11/24.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 27. 二叉树的镜像
/// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

namespace mirrorTree
{
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution {
    public:
        TreeNode* mirrorTree(TreeNode* root) {
            if(!root || (!root->left && !root->right)) return root;
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            mirrorTree(root->left);
            mirrorTree(root->right);

            return root;
        }
    };
}
