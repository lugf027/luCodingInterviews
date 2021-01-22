/*************************************************************
 * Name     : 61_rotateRight
 * Title    : 61. 旋转链表
 * Author   : lugf027 18:29 2021/1/14.
 * Describe :
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 *************************************************************/

#include "util.h"

namespace rotateRight {

    class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == nullptr) return head;

            ListNode *res = head;
            ListNode *headCp = head;
            int length = 0;
            while (head) {
                ++length;
                head = head->next;
            }
            head = headCp;
            k = k % length;
            if (k == 0) return head;

            // 这里 k-1, 为了下方截断
            for (int i = 0; i < k + 1; ++i) {
                head = head->next;
            }

            while (head) {
                head = head->next;
                headCp = headCp->next;
            }
            head = res;

            res = headCp->next;
            ListNode *resRet = res;

            headCp->next = nullptr;
            while (res->next) {
                res = res->next;
            }
            res->next = head;
            return resRet;
        }
    };

/**
 * 优化
 */

    class Solution1 {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head) return head;
            ListNode *headCp = head;

            int length = 1;
            while (head->next) {
                ++length;
                head = head->next;
            }
            head->next = headCp;

            ListNode *newTail = head;
            for (int i = 0; i < length - k % length; ++i)
                newTail = newTail->next;

            ListNode *newHead = newTail->next;
            newTail->next = nullptr;

            return newHead;
        }
    };
}
