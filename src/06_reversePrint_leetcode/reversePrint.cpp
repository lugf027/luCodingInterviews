/********************************************
* reversePrint.cpp                              *
* Created by lugf027 on 2020/10/12.            *
* Github: https://github.com/lugf027        *
*********************************************/
#include <vector>
#include <cstddef>
#include <iostream>

using namespace std;

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

/// 本人用的递归，但有人评论说：“当链表非常长的时候，这会导致函数调用的层级很深，
/// 从而可能导致函数调用栈溢出。显然，基于用栈基于循环的代码鲁棒性比这个好。”

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 本人递归的辅助函数
     * @param head
     * @param ret
     */
    void reversePrintAux(ListNode *head, vector<int> *ret) {
        if (head->next != NULL) {
            reversePrintAux(head->next, ret);
        }
        ret->push_back(head->val);
    }

    /**
     * 带辅助函数的递归
     * 因为自己以为会不带辅助函数，会疯狂地进行 vector 的创建和拷贝了
     * @param head
     * @return
     */
    vector<int> reversePrint(ListNode *head) {
        vector<int> tmpRet;
        /// 本人第一次做时，未考虑 head 为 nullptr
        /// 导致 reversePrintAux 意外访问 nullptr->val
        if (head != NULL) {
            reversePrintAux(head, &tmpRet);
        }
        return tmpRet;
    }

    /**
     * 不带辅助函数的递归
     * @param head
     * @return
     */
    vector<int> reversePrint1(ListNode *head) {
        vector<int> tmpRet;
        if (head == NULL)
            return tmpRet;

        tmpRet = reversePrint1(head->next);
        tmpRet.push_back(head->val);
        return tmpRet;
    }

    /**
     * 使用栈来解决
     * @param head
     * @return
     */
    vector<int> reversePrint2(ListNode *head) {
        vector<int> ret;
        if (head == NULL)
            return ret;

        vector<ListNode *> tmpStack;
        ListNode *now = head;
        // 进栈
        while (now != NULL) {
            tmpStack.push_back(now);
            now = now->next;
        }

        // 出栈
        while (!tmpStack.empty()) {
            ret.push_back(tmpStack.at(tmpStack.size() - 1)->val);
            tmpStack.pop_back();
        }

        return ret;
    }

    // 递归反转链表
    ListNode *reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* tmpList = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmpList;
    }

    // 非递归反转链表
    ListNode *reverseList2(ListNode *head) {
        ListNode *pre = NULL;

        while (head != NULL){
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    /**
     * 先反转链表
     * @param head
     * @return
     */
    vector<int> reversePrint3(ListNode *head) {
        vector<int> ret;
        if (head == NULL)
            return ret;
        ListNode *now = reverseList(head);

        while (now != NULL) {
            ret.push_back(now->val);
            now = now->next;
        }

        return ret;
    }


};