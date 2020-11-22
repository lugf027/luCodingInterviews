/********************************************
* treeToDoublyList.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 36. 二叉搜索树与双向链表
/// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
/// 要求不能创建任何新的节点，只能调整树中节点指针的指向。

#include <vector>

using namespace std;

namespace treeToDoublyList {
    class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node() {}

        Node(int _val) {
            val = _val;
            left = nullptr;
            right = nullptr;
        }

        Node(int _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };

    class Solution {
    public:
        Node* treeToDoublyList(Node* root) {
            if (!root) return nullptr;

            vector<Node*> nodeVector;
            preOrderTraversal(root, nodeVector);

            for (int i = 0; i < nodeVector.size() - 1; ++i) {
                nodeVector[i]->right = nodeVector[i + 1];
                nodeVector[i + 1]->left = nodeVector[i];
            }
            nodeVector.back()->right = nodeVector.front();
            nodeVector.front()->left = nodeVector.back();
            return nodeVector.front();
        }

        void preOrderTraversal(Node* root, vector<Node*> &nodeVector) {
            if (root) {
                preOrderTraversal(root->left, nodeVector);
                nodeVector.push_back(root);
                preOrderTraversal(root->right, nodeVector);
            }
        }
    };
}
