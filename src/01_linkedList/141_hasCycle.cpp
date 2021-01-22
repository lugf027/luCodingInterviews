/*************************************************************
 * Name     : 141_hasCycle
 * Title    : 141. 环形链表
 * Author   : lugf027 10:43 2021/1/15.
 * Describe :
 * 给定一个链表，判断链表中是否有环。
 *************************************************************/

#include "util.h"

namespace hasCycle {
    /**
     * 快慢指针
     */
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *headIterStep2 = head;
            while (headIterStep2 && headIterStep2->next) {
                headIterStep2 = headIterStep2->next->next;
                head = head->next;
                if (headIterStep2 == head) return true;
            }
            return false;
        }
    };

    /**
     * unordered_set
     */
    class Solution1 {
    public:
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode *> visited;
            while (head) {
                if (visited.find(head) != visited.end()) return true;
                visited.insert(head);
                head = head->next;
            }
            return false;
        }
    };
}
