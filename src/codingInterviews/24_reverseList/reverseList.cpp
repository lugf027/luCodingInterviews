/********************************************
* reverseList.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 24. 反转链表
/// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

namespace reverseList
{
    struct ListNode
    {
        int val;
        ListNode* next;
        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    /**
     * 循环
     */
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* res = nullptr;
            while(head != nullptr)
            {
                ListNode* next = head->next;
                head->next = res;
                res = head;
                head = next;
            }
            return res;
        }
    };
}
