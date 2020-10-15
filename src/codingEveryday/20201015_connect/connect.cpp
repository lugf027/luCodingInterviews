/********************************************
* connect.cpp                              *
* Created by lugf027 on 2020/10/15.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <cstddef>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    /**
     * 队列 时间o(N), 空间o(N)
     * @param root
     * @return
     */
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;

        queue<Node *> Q;
        Q.push(root);

        // 遍历各个层
        while (!Q.empty()) {
            int size = Q.size();

            // 遍历此层节点
            for (int i = 0; i < size; ++i) {
                Node *node = Q.front();
                Q.pop();

                if (i < size - 1) {
                    node->next = Q.front();
                }

                if (node->left != nullptr)
                    Q.push(node->left);
                if (node->right != nullptr)
                    Q.push(node->right);
            }
        }

        return root;
    }

    /**
     * 递推？时间o(N), 空间o(1)
     * @param root
     * @return
     */
    Node* connect1(Node* root) {
        if (root == nullptr) {
            return root;
        }

        // 从根节点开始
        Node* leftmost = root;

        while (leftmost->left != nullptr) {

            // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
            Node* head = leftmost;

            while (head != nullptr) {

                // CONNECTION 1
                head->left->next = head->right;

                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                // 指针向后移动
                head = head->next;
            }

            // 去下一层的最左的节点
            leftmost = leftmost->left;
        }

        return root;
    }
};
