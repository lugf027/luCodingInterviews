/********************************************
* buildTree.cpp                              *
* Created by lugf027 on 2020/10/13.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <vector>
#include <cstddef>

using namespace std;

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图所示的二叉树并输出它的头结点。
//  3
// / \
//9  20
//  /  \
// 15   7

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * 思路：递归分别求左、右子树
     * 执行用时：328 ms, 在所有 C++ 提交中击败了5.08%的用户
     * 内存消耗：157.5 MB, 在所有 C++ 提交中击败了5.08%的用户
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        auto *root = new TreeNode(preorder.at(0));
        if (preorder.size() == 1) {
            return root;
        }

        /// 生成左、右子树
        vector<int> preOrderLeftAux;
        vector<int> inOrderLeftAux;
        vector<int> preOrderRightAux;
        vector<int> inOrderRightAux;

        for (int i = 0; inorder.at(i) != preorder.at(0);) {
            inOrderLeftAux.push_back(inorder.at(i));
            preOrderLeftAux.push_back(preorder.at(++i));
        }

        for (int i = preOrderLeftAux.size() + 1; i < preorder.size(); ++i) {
            inOrderRightAux.push_back(inorder.at(i));
            preOrderRightAux.push_back(preorder.at(i));
        }

        root->left = buildTree(preOrderLeftAux, inOrderLeftAux);
        root->right = buildTree(preOrderRightAux, inOrderRightAux);

        return root;
    }

    /**
     * 使用指针解决
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
        return buildTree1Aux(0, 0, (int) inorder.size() - 1, preorder, inorder);
    }

    /**
     * 辅助函数，递归解决
     * @param preStart 前序遍历开始的位置
     * @param inStart 中序遍历开始的位置
     * @param inEnd 中序遍历结束的位置
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode *buildTree1Aux(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return NULL;

        // 创建节点
        auto *root = new TreeNode(preorder.at(preStart));
        int index = 0;

        // 找到当前节点 root 在中序遍历中的位置，然后把数组分两半
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }

        root->left = buildTree1Aux(preStart + 1, inStart, index - 1, preorder, inorder);
        root->right = buildTree1Aux(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder);
        return root;
    }

    /**
     * 使用栈解决
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        vector<TreeNode *> orderStack;
        auto *root = new TreeNode(preorder.at(0));
        TreeNode *cur = root;

        // 对于前序遍历相邻两个节点的的关系
        for (int i = 1, j = 0; i < preorder.size(); ++i) {
            if (cur->val != inorder[j]) {           // 第一种情况,左子树
                cur->left = new TreeNode(preorder[i]);
                orderStack.push_back(cur);
                cur = cur->left;
            } else {                                // 第二种情况，右子树或某个祖先节点右节点的值
                j++;
                while (!orderStack.empty() && orderStack.at(orderStack.size() - 1)->val == inorder[j]) {
                    cur = orderStack.at(orderStack.size() - 1);
                    orderStack.pop_back();
                    ++j;
                }
                // 给cur添加右节点
                cur = cur->right = new TreeNode(preorder.at(i));
            }
        }
        return root;
    }

#include<limits.h>

    /**
     * 递归的另一种解法
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder) {
        return buildTree3Aux(preorder, inorder, INT_MIN);
    }

    TreeNode *buildTree3Aux(vector<int> &preorder, vector<int> &inorder, int stop) {
        if (preN >= preorder.size())
            return NULL;

        if(inorder.at(inN) == stop){
            ++inN;
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder.at(preN++));
        node->left = buildTree3Aux(preorder, inorder, node->val);
        node->right = buildTree3Aux(preorder, inorder, stop);

        return node;
    }

private:
    int inN = 0;
    int preN = 0;
};
