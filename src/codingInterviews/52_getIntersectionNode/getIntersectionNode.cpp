/********************************************
* getIntersectionNode.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 52. 两个链表的第一个公共节点
/// 输入两个链表，找出它们的第一个公共节点。

/// 如果两个链表没有交点，返回 null.
/// 在返回结果后，两个链表仍须保持原有的结构。
/// 可假定整个链表结构中没有循环。
/// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

#include <unordered_set>
using namespace std;

namespace getIntersectionNode
{

    struct ListNode
    {
        int val;
        ListNode* next;
        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    /**
     * unordered_set
     * not match the request condition
     */
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode*> headASet;
            while (headA)
            {
                headASet.insert(headA);
                headA = headA->next;
            }
            while (headB)
            {
                if(headASet.find(headB) != headASet.end())
                    return headB;
                headB=headB->next;
            }
            return nullptr;
        }
    };

    /**
     * double pointers
     */
    class Solution1 {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *node1 = headA;
            ListNode *node2 = headB;

            while (node1 != node2) {
                node1 = node1 != nullptr ? node1->next : headB;
                node2 = node2 != nullptr ? node2->next : headA;
            }
            return node1;
        }
    };
}
