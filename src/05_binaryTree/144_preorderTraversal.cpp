/*************************************************************
 * Name     : 144_preorderTraversal
 * Title    : 
 * Author   : lugf027 10:27 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace preorderTraversal {

    /**
     * 递归
     */
    class Solution {
    private:
        void preOrder(TreeNode *root, vector<int> &res) {
            if (!root) return;
            res.push_back(root->val);
            if (root->left) preOrder(root->left, res);
            if (root->right) preOrder(root->right, res);
        }

    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            preOrder(root, res);
            return res;
        }
    };

    /**
     * 迭代
     */
    class Solution1 {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }

            stack<TreeNode*> stk;

            while (!stk.empty() || root){
                while (root!= nullptr){
                    res.emplace_back(root->val);
                    stk.emplace(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                root = root->right;
            }

            return res;
        }
    };

    /**
     * Morris
     */
    class Solution2 {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }

            TreeNode *predecessor = nullptr;

            while (root!= nullptr){
                predecessor = root->left;
                if(predecessor){
                    while (predecessor->right && predecessor->right!=root){
                        predecessor = predecessor->right;
                    }
                    if(predecessor->right == nullptr){
                        res.emplace_back(root->val);
                        predecessor->right = root;
                        root = root->left;
                    }else{
                        predecessor->right = nullptr;
                        root = root->right;
                    }
                }else{
                    res.emplace_back(root->val);
                    root = root->right;
                }
            }

            return res;
        }
    };

}
