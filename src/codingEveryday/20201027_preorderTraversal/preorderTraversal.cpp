/********************************************
* preorderTraversal.cpp                              *
* Created by lugf027 on 2020/10/27.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 144. 二叉树的前序遍历
/// 给定一个二叉树，返回它的 前序 遍历。

#include <vector>
#include <stack>

using namespace std;

namespace preorderTraversal {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    /**
     * 利用栈来迭代
     */
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr)
                return res;

            stack<TreeNode *> s;

            s.push(root);
            while (!s.empty()) {
                TreeNode *temp = s.top();
                s.pop();
                res.push_back(temp->val);
                if (temp->right != nullptr) s.push(temp->right);
                if (temp->left != nullptr) s.push(temp->left);
            }

            return res;
        }
    };

    /**
     * Morris 遍历
     */
    class Solution1 {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            if (root == nullptr) {
                return res;
            }

            TreeNode *p1 = root, *p2 = nullptr;

            while (p1 != nullptr) {
                p2 = p1->left;
                if (p2 != nullptr) {
                    while (p2->right != nullptr && p2->right != p1) {
                        p2 = p2->right;
                    }
                    if (p2->right == nullptr) {
                        res.emplace_back(p1->val);
                        p2->right = p1;
                        p1 = p1->left;
                        continue;
                    } else {
                        p2->right = nullptr;
                    }
                } else {
                    res.emplace_back(p1->val);
                }
                p1 = p1->right;
            }
            return res;
        }
    };
}
