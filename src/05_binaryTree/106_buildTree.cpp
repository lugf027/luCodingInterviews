/*************************************************************
 * Name     : 106_buildTree
 * Title    : 106. 从中序与后序遍历序列构造二叉树
 * Author   : lugf027 16:12 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace buildTree1 {
    class Solution {
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            if (inorder.empty() || postorder.empty()) return nullptr;

            auto *rootRes = new TreeNode(postorder.back());

            for (int i = 0; i < inorder.size(); ++i) {
                if (inorder[i] == postorder.back()) {
                    vector<int> leftInorderTmp(vector<int>(inorder.begin(), inorder.begin() + i));
                    vector<int> leftPostorderTmp(vector<int>(postorder.begin(), postorder.begin() + i));
                    rootRes->left = buildTree(leftInorderTmp, leftPostorderTmp);

                    vector<int> rightInorderTmp(vector<int>(inorder.begin() + i + 1, inorder.begin() + inorder.size()));
                    vector<int> rightPostorderTmp(
                            vector<int>(postorder.begin() + i, postorder.begin() + postorder.size() - 1));
                    rootRes->right = buildTree(rightInorderTmp, rightPostorderTmp);
                }
            }

            return rootRes;
        }
    };
}
