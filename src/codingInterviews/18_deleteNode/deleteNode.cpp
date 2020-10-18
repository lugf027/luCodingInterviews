/********************************************
* deleteNode.cpp                              *
* Created by lugf027 on 2020/10/18.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <cstddef>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if(head == NULL) return head;

        if (head->val == val)
            return head->next;

        ListNode *pre = head;
        while (pre->next != NULL) {
            if (pre->next->val == val) {
                pre->next = pre->next->next;
                return head;
            }
            pre = pre->next;
        }

        return head;
    }
};