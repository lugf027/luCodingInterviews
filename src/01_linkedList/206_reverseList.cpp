/*************************************************************
 * Name     : 206_reverseList
 * Title    : 206. 反转链表
 * Author   : lugf027 11:09 2021/1/15.
 * Describe :
 * 反转一个单链表。
 *************************************************************/

#include "util.h"

namespace reverseList {
    /**
     * iteration
     */
    class Solution {
    public:
        ListNode *reverseList(ListNode *head) {
            if (!head) return head;
            ListNode *res = head;
            head = head->next;
            ListNode *tmp;

            while (head) {
                tmp = res;
                res = head;
                res->next = tmp;
                head = head->next;
            }
            return res;
        }
    };

    /**
     * recursion
     */
    class Solution1 {
    public:
        ListNode *reverseList(ListNode *head) {
            if (!head || !head->next) return head;

            ListNode *reversedTail = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return reversedTail;
        }
    };
}
