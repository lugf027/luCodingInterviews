/*************************************************************
 * Name     : 92_reverseBetween
 * Title    : 92. 反转链表 II
 * Author   : lugf027 12:30 2021/1/15.
 * Describe :
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *************************************************************/

#include "util.h"

namespace reverseBetween {
    class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode *resPre = new ListNode(-1);
            ListNode *stepI = resPre;
            resPre->next = head;
            // stepI 指向第 m 个元素的前置链表
            for (int i = 1; i < m; ++i) {
                stepI = stepI->next;
            }
            ListNode *startI = stepI->next;
            stepI->next = nullptr;

            ListNode *tmp = nullptr;
            for (int i = m; i < n + 1; ++i) {
                tmp = stepI->next;
                stepI->next = startI;
                startI = startI->next;
                stepI->next->next = tmp;
            }

            while (stepI->next) stepI = stepI->next;
            stepI->next = startI;
            return resPre->next;
        }
    };
}
