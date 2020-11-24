/********************************************
* isSubStructure.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/


/// 剑指 Offer 26. 树的子结构
/// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
/// B是A的子结构， 即 A中有出现和B相同的结构和节点值。

#include <string>

using namespace std;

namespace isSubStructure {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    /**
     * 前序遍历找字串
     * 有 bug
     * 如A: 1,2,3,4 B:3,1
     */
    class Solution {
    public:
        bool isSubStructure(TreeNode* A, TreeNode* B) {
            if (!A || !B) return false;
            string aStr = getPreStrByTreeNode(A);
            string bStr = getPreStrByTreeNode(B);

            return aStr.find(bStr) != string::npos;
        }

        string getPreStrByTreeNode(TreeNode* root) {
            string res;
            if (root) {
                res += getPreStrByTreeNode(root->left);
                res += std::to_string(root->val);

                res += getPreStrByTreeNode(root->right);
            }
            return res;
        }
    };

    /**
     * CodingInterviews
     */
    class Solution1 {
    public:
        bool isSubStructure(TreeNode* A, TreeNode* B) {
            bool res = false;
            if (A && B) {
                if (!NotEqual(A->val, B->val))
                    res = isSubStructureAux(A, B);
                if (!res)
                    res = isSubStructure(A->left, B);
                if (!res)
                    res = isSubStructure(A->right, B);
            }
            return res;
        }

        bool isSubStructureAux(TreeNode* A, TreeNode* B) {
            if (!B) return true;

            if (!A) return false;
            if (NotEqual(A->val, B->val)) return false;
            return isSubStructureAux(A->left, B->left) && isSubStructureAux(A->right, B->right);
        }

    private:
        inline bool NotEqual(double num1, double num2) {
            return ((num1 - num2) > 0.0000001f) || ((num2 - num1) > 0.0000001f);
        }
    };
}