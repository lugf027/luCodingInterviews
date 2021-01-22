/*************************************************************
 * Name     : 369_plusOne
 * Title    : 369. 给单链表加一
 * Author   : lugf027 13:44 2021/1/20.
 * Describe :
 * 用一个 非空 单链表来表示一个非负整数，然后将这个整数加一。
 * 你可以假设这个整数除了 0 本身，没有任何前导的 0。
 * 这个整数的各个数位按照 高位在链表头部、低位在链表尾部 的顺序排列。
 *************************************************************/

#include "util.h"

namespace plusOne {
    class Solution1 {
    public:
        ListNode *plusOne(ListNode *head) {
            ListNode *lastNine = nullptr;
            ListNode *headCp = head;
            while (head) {
                if (head->val != 9) {
                    lastNine = head;
                }
                head = head->next;
            }

            if (lastNine) {
                lastNine->val += 1;
                while (lastNine->next) {
                    lastNine = lastNine->next;
                    lastNine->val = 0;
                }
                return headCp;
            } else {
                lastNine = new ListNode(1);
                lastNine->next = headCp;
                while (headCp) {
                    headCp->val = 0;
                    headCp = headCp->next;
                }
                return lastNine;
            }
        }
    };

    /**
     * 递归
     */
    class Solution {
    public:
        int plusOneAux(ListNode *head) {
            if (head->next == nullptr) {
                if (head->val == 9) {
                    head->val = 0;
                    return 1;
                } else {
                    head->val += 1;
                }
            } else {
                int resTail = plusOneAux(head->next);
                if (resTail == 1) {
                    if (head->val == 9) {
                        head->val = 0;
                        return 1;
                    } else {
                        head->val += 1;
                    }
                } else {
                    return 0;
                }
            }
            return 0;
        }

        ListNode *plusOne(ListNode *head) {
            int resTail = plusOneAux(head);
            if (resTail == 1) {
                if (head->val == 0) {
                    head->val = 0;
                    ListNode *res = new ListNode(1);
                    res->next = head;
                    return res;
                } else {
                    head->val += 1;
                    return head;
                }
            } else {
                return head;
            }
        }
    };
}
