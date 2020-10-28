/********************************************
* sumNumbers.cpp                              *
* Created by lugf027 on 2020/10/29.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 129. 求根到叶子节点数字之和
/// 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
/// 例如，从根到叶子节点路径 1->2->3 代表数字 123。
/// 计算从根到叶子节点生成的所有数字之和。
/// 说明: 叶子节点是指没有子节点的节点。


#include <cstddef>

#include <queue>

using namespace std;

namespace sumNumbers {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    /**
     * 深度优先算法
     */
    class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            return sumNumbersAux(root, 0);
        }

    private:
        int sumNumbersAux(TreeNode *root, int pre) {
            if (root == nullptr) return 0;
            if (root->left == nullptr && root->right == nullptr)
                return pre + root->val;
            return sumNumbersAux(root->left, 10 * (pre + root->val)) +
                   sumNumbersAux(root->right, 10 * (pre + root->val));
        }
    };


    /**
     * 广度优先，使用队列
     */
    class Solution1 {
    public:
        int sumNumbers(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            int sum = 0;
            queue<TreeNode*> nodeQueue;
            queue<int> numQueue;
            nodeQueue.push(root);
            numQueue.push(root->val);

            while (!nodeQueue.empty()) {
                TreeNode* node = nodeQueue.front();
                int num = numQueue.front();
                nodeQueue.pop();
                numQueue.pop();
                TreeNode* left = node->left;
                TreeNode* right = node->right;

                if (left == nullptr && right == nullptr) {
                    sum += num;
                } else {
                    if (left != nullptr) {
                        nodeQueue.push(left);
                        numQueue.push(num * 10 + left->val);
                    }
                    if (right != nullptr) {
                        nodeQueue.push(right);
                        numQueue.push(num * 10 + right->val);
                    }
                }
            }

            return sum;
        }
    };
}
