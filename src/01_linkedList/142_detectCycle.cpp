/*************************************************************
 * Name     : 142_detectCycle
 * Title    : 142. 环形链表 II
 * Author   : lugf027 10:53 2021/1/15.
 * Describe :
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *************************************************************/

#include "util.h"

namespace detectCycle {

    /**
     * 快慢指针: o(1) 空间
     */
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow) {
                    while (head != slow) {
                        head = head->next;
                        slow = slow->next;
                    }
                    return head;
                }
            }
            return nullptr;
        }
    };

    /**
     * unordered_set
     */
    class Solution1 {
    public:
        ListNode *detectCycle(ListNode *head) {
            unordered_set<ListNode *> visited;
            while (head) {
                if (visited.find(head) != visited.end()) return head;
                visited.insert(head);
                head = head->next;
            }
            return nullptr;
        }
    };
}