/*************************************************************
 * Name     : 105_buildTree
 * Title    : 105. 从前序与中序遍历序列构造二叉树
 * Author   : lugf027 17:16 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        auto rootRes = new TreeNode(preorder[0]);

        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                vector<int> leftPreorderTmp(vector<int>(preorder.begin() + 1, preorder.begin() + i + 1));
                vector<int> leftInorderTmp(vector<int>(inorder.begin(), inorder.begin() + i));
                rootRes->left = buildTree(leftPreorderTmp, leftInorderTmp);

                vector<int> rightPreorderTmp(vector<int>(preorder.begin() + i + 1, preorder.begin() + preorder.size()));
                vector<int> rightInorderTmp(vector<int>(inorder.begin() + i + 1, inorder.begin() + inorder.size()));
                rootRes->right = buildTree(rightPreorderTmp, rightInorderTmp);
            }
        }

        return rootRes;
    }
};
