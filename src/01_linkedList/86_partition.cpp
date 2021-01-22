/*************************************************************
 * Name     : 86_partition
 * Title    : 86. 分隔链表
 * Author   : lugf027 9:38 2021/1/15.
 * Describe :
 * 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
 *************************************************************/

#include "util.h"

namespace partition {
    /**
     * 把小的依次挑出来作为新链表，再连接大的剩余的
     */
    class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            if (head == nullptr) return head;

            auto *headLessPre = new ListNode(-1);
            ListNode *headLessPreCp = headLessPre;

            if (head->val < x) {
                headLessPre->next = head;
                headLessPre = headLessPre->next;
                while (head->next && head->next->val < x) {
                    head = head->next;
                    headLessPre = headLessPre->next;
                }
                head = head->next;
            }
            ListNode *headGOrE = head;
            ListNode *headGOrECp = headGOrE;

            while (headGOrE && headGOrE->next) {
                while (headGOrE->next && headGOrE->next->val < x) {
                    headLessPre->next = headGOrE->next;
                    headLessPre = headLessPre->next;
                    headGOrE->next = headGOrE->next->next;
                }
                headGOrE = headGOrE->next;
            }

            headLessPre->next = headGOrECp;
            return headLessPreCp->next;
        }
    };

    /**
     * 分别挑出来小的、大的
     */
    class Solution1 {
    public:
        ListNode *partition(ListNode *head, int x) {
            auto *less = new ListNode(-1);
            ListNode *lessCp = less;
            auto *gOrE = new ListNode(-1);
            ListNode *gOrECp = gOrE;
            while (head != nullptr) {
                if (head->val < x) {
                    less->next = head;
                    less = less->next;
                } else {
                    gOrE->next = head;
                    gOrE = gOrE->next;
                }
                head = head->next;
            }
            gOrE->next = nullptr;
            less->next = gOrECp->next;
            return lessCp->next;
        }
    };
}
