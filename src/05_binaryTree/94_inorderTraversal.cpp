/*************************************************************
 * Name     : 94_inorderTraversal
 * Title    : 94. 二叉树的中序遍历
 * Author   : lugf027 20:12 2021/2/25.
 * Describe : 
 *************************************************************/
#include "util.h"

namespace inorderTraversal {
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;

            if (root == nullptr) return res;

            auto left = inorderTraversal(root->left);
            if (!left.empty())
                res.insert(res.end(), left.begin(), left.end());

            res.push_back(root->val);

            auto right = inorderTraversal(root->right);
            if (!right.empty())
                res.insert(res.end(), right.begin(), right.end());

            return res;
        }
    };

    /**
     * 美观
     */
    class Solution1 {
    public:
        void inorder(TreeNode *root, vector<int> &res) {
            if (!root) {
                return;
            }
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }

        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            inorder(root, res);
            return res;
        }
    };

    /**
     * 迭代
     */
    class Solution2 {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> stk;
            while (root != nullptr || !stk.empty()) {
                while (root != nullptr) {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
            return res;
        }
    };

    /**
     * Morris 中序遍历
     */
    class Solution3 {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            TreeNode *predecessor = nullptr;

            while (root != nullptr) {
                if (root->left != nullptr) {
                    // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                    predecessor = root->left;
                    while (predecessor->right != nullptr && predecessor->right != root) {
                        predecessor = predecessor->right;
                    }

                    // 让 predecessor 的右指针指向 root，继续遍历左子树
                    if (predecessor->right == nullptr) {
                        predecessor->right = root;
                        root = root->left;
                    }
                        // 说明左子树已经访问完了，我们需要断开链接
                    else {
                        res.push_back(root->val);
                        predecessor->right = nullptr;
                        root = root->right;
                    }
                }
                    // 如果没有左孩子，则直接访问右孩子
                else {
                    res.push_back(root->val);
                    root = root->right;
                }
            }
            return res;
        }
    };

    class Solution13 {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            TreeNode *predecessor = nullptr;

            while (root != nullptr){
                if(root->left != nullptr){
                    predecessor = root->left;
                    while (predecessor->right!= nullptr && predecessor->right!= root){
                        predecessor=predecessor->right;
                    }

                    if(predecessor->right == nullptr){
                        predecessor->right = root;
                        root = root->left;
                    }else{
                        predecessor->right = nullptr;
                        res.push_back(root->val);
                        root = root->right;
                    }
                }else{
                    res.push_back(root->val);
                    root = root->right;
                }
            }

            return res;
        }
    };
}
