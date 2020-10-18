/********************************************
* removeNthFromEnd.cpp                              *
* Created by lugf027 on 2020/10/18.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 19. 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
/// n 是有效的

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 一次遍历, first 比 second 超前 n 个节点; first 到尽头, second 删除下一个
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *headTemp = new ListNode(0, head);
        ListNode *listNodeTemp = headTemp;
        ListNode *listNodeRmNext = headTemp;

        for (int i = 0; i <= n; ++i) {
            listNodeTemp = listNodeTemp->next;
        }
        while (listNodeTemp) {
            listNodeTemp = listNodeTemp->next;
            listNodeRmNext = listNodeRmNext->next;
        }
        listNodeRmNext->next = listNodeRmNext->next->next;

        ListNode *res = headTemp->next;
        delete headTemp;

        return res;
    }
};

/**
 * 先遍历一遍，计算链表长度
 */
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;

        int listLen = 0;
        ListNode *tempLen = head;
        while (tempLen) {
            ++listLen;
            tempLen = tempLen->next;
        }

        if (n == listLen)
            return head->next;

        ListNode *temp = head;
        for (int i = 1; i < listLen - n; ++i) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};

#include <stack>
using namespace std;

/**
 * 栈
 */
class Solution3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
