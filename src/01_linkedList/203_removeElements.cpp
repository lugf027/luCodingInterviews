/*************************************************************
 * Name     : 203_removeElements
 * Title    : 203. 移除链表元素
 * Author   : lugf027 10:26 2021/1/15.
 * Describe :
 * 删除链表中等于给定值 val 的所有节点。
 *************************************************************/

#include "util.h"

namespace removeElements {
    class Solution {
    public:
        ListNode *removeElements(ListNode *head, int val) {
            while (head && head->val == val) {
                head = head->next;
            }
            ListNode *res = head;
            while (head && head->next) {
                if (head->next && head->next->val == val) {
                    ListNode *tmp = head;
                    while (head->next && head->next->val == val) {
                        head = head->next;
                    }
                    tmp->next = head->next;
                }
                head = head->next;
            }
            return res;
        }
    };
}
