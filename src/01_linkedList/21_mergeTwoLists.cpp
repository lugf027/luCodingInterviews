/*************************************************************
 * Name     : 21_mergeTwoLists
 * Title    : 21. 合并两个有序链表
 * Author   : lugf027 15:53 2021/1/14.
 * Describe :
 * 将两个升序链表合并为一个新的 升序 链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 *************************************************************/

#include "util.h"

namespace mergeTwoLists {
    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            auto *resPre = new ListNode(-1);
            ListNode *resPreCp = resPre;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    resPre->next = l1;
                    l1 = l1->next;
                } else {
                    resPre->next = l2;
                    l2 = l2->next;
                }
                resPre = resPre->next;
            }
            resPre->next = l1 ? l1 : l2;

            resPre = resPreCp->next;
            delete resPreCp;
            return resPre;

            // return resPreCp->next;
        }
    };
}
