/********************************************
* copyRandomList.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 35. 复杂链表的复制
/// 请实现 copyRandomList 函数，复制一个复杂链表。
/// 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
/// 还有一个 random 指针指向链表中的任意节点或者 null。

#include <unordered_map>

using namespace std;

namespace copyRandomList {
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> nodeMap;
            Node* res = new Node(0);

            Node* pre = res;
            Node* param = head;
            while (head)
            {
                res->next = new Node(head->val);
                res = res->next;
                nodeMap.insert(make_pair(head, res));
                head=head->next;
            }
            head = param;
            res=pre->next;
            while (head)
            {
                if(head->random)
                {
                    res->random = nodeMap[head->random];
                }
                head=head->next;
                res=res->next;
            }
            res=pre->next;
            delete pre;
            head=param;
            return res;
        }
    };
}