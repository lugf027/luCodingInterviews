/*************************************************************
 * Name     : 145_postorderTraversal
 * Title    : 145. 二叉树的后序遍历
 * Author   : lugf027 11:10 2021/2/26.
 * Describe : 
 *************************************************************/
#include "util.h"

namespace postorderTraversal {
    class Solution {
    private:
        void afterOrder(TreeNode *root, vector<int> &res) {
            if (!root) return;
            if (root->left) afterOrder(root->left, res);
            if (root->right) afterOrder(root->right, res);
            res.push_back(root->val);
        }

    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            afterOrder(root, res);
            return res;
        }
    };


    class Solution1 {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }

            stack<TreeNode *> stk;
            TreeNode *prev = nullptr; // 主要记录右子树已经遍历过了

            while (!stk.empty() || root) {
                while (root != nullptr) {
                    stk.emplace(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (root->right == nullptr || root->right == prev) {
                    res.emplace_back(root->val);
                    prev = root;
                    root = nullptr;
                } else {
                    stk.emplace(root);
                    root = root->right;
                }
            }

            return res;
        }
    };

    class Solution2 {
    private:
        void addPath(vector<int> &vec, TreeNode *node) {
            int count = 0;
            while (node != nullptr) {
                ++count;
                vec.emplace_back(node->val);
                node = node->right;
            }
            reverse(vec.end() - count, vec.end());
        }

    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }
            TreeNode *predecessor = nullptr;
            TreeNode *rootTmp = root;
            while (root) {
                predecessor = root->left;
                if (predecessor) {
                    while (predecessor->right && predecessor->right != root) {
                        predecessor = predecessor->right;
                    }
                    if (predecessor->right == nullptr) {
                        predecessor->right = root;
                        root = root->left;
                        continue;
                    } else {
                        predecessor->right = nullptr;
                        addPath(res, root->left);
                    }
                }
                root = root->right;
            }
            addPath(res, rootTmp);
            return res;
        }
    };


}
