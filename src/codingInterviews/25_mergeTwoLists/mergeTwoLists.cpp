/********************************************
* mergeTwoLists.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 25. 合并两个排序的链表
/// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

namespace mergeTwoLists {

    struct ListNode {
        int val;
        ListNode* next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            auto* res = new ListNode(0);
            ListNode* pre = res;

            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val >= l2->val) {
                    ListNode* l2Next = l2->next;
                    res->next = l2;
                    res=res->next;
                    l2 = l2Next;
                }
                else {
                    ListNode* l1Next = l1->next;
                    res->next = l1;
                    res=res->next;
                    l1 = l1Next;
                }
            }
            if(l1) res->next = l1;
            if(l2) res->next = l2;

            res = pre->next;
            delete pre;
            return res;
        }
    };
}
