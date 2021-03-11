/********************************************
* swapPairs.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

#include <iostream>
namespace swapPairs {


    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}

        void print() {
            printf("%d\t", val);
            if (next != nullptr) next->print();
            else printf("\n");
        }

    };

    class Solution {
    public:
        /**
         * 每次递归替换两个
         * @param head
         * @return
         */
        ListNode *swapPairs(ListNode *head) {
            if (head == nullptr) {
                return nullptr;
            }
            if (head->next == nullptr) {
                return head;
            }
            ListNode *tmp = new ListNode(head->val, head->next->next);
            head = head->next;
            head->next = tmp;
            head->next->next = swapPairs(head->next->next);
            return head;
        }

        /**
         * 每次递归替换两个的优化
         * @param head
         * @return
         */
        ListNode *swapPairs1(ListNode *head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode *tmp = head;
            head = head->next;
            tmp->next = swapPairs(head->next);
            head->next = tmp;
            return head;
        }

        /**
         * 官方的更简洁一些
         * @param head
         * @return
         */
        ListNode *swapPairs8(ListNode *head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode *newHead = head->next;
            head->next = swapPairs(newHead->next);
            newHead->next = head;
            return newHead;
        }

        /**
         * 非递归
         * @param head
         * @return
         */
        ListNode *swapPairs2(ListNode *head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }

            ListNode *newHead = head->next;
            ListNode *tmpFirst = head;  // 步进
            ListNode *tmp;              // 交换时的临时变量

            // 错误原因，节点插入错误
            while (tmpFirst != nullptr && tmpFirst->next != nullptr) {
                tmp = tmpFirst->next;  // t:2
                tmpFirst->next = tmpFirst->next->next;  // 1->2 => 1->3
                tmp->next = tmpFirst;  // t->3 => t->1 => 2->1
                tmpFirst = tmpFirst->next;  // 1 => 3
            }

            return newHead;
        }

        /**
         * 非递归 改正
         * @param head
         * @return
         */
        ListNode *swapPairs2_1(ListNode *head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }

            ListNode *newHead = head->next;

            ListNode *tmp = head->next;             // 交换时的临时变量
            head->next = tmp->next;
            tmp->next = head;
            ListNode *pre = tmp->next;

            // pre 在需要交换的两个的上一个位置 pre->exchange0->exchange1
            while (pre->next != nullptr && pre->next->next != nullptr) {
                tmp = pre->next->next;            // tmp := exchange1
                pre->next->next = tmp->next;    // exchange0->next := exchange1->next
                tmp->next = pre->next;          // exchange1->next := exchange0
                pre->next = tmp;                // pre->next       := exchange1
                pre = tmp->next;                  // pre := exchange0
            }

            return newHead;
        }

        /**
         * 交换值
         * @param head
         * @return
         */
        ListNode *swapPairs3(ListNode *head) {
            int first;
            ListNode *temp = head;

            while (temp != nullptr && temp->next != nullptr) {
                first = temp->val;
                temp->val = temp->next->val;
                temp->next->val = first;
                temp = temp->next->next;
            }

            return head;
        }
    };

    int main() {
        ListNode *a0 = new ListNode(0);
        ListNode *a1 = new ListNode(1);
        ListNode *a2 = new ListNode(2);
        ListNode *a3 = new ListNode(3);
        ListNode *a4 = new ListNode(4);
        ListNode *a5 = new ListNode(5);

        a0->next = a1;
        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;

        Solution solution;
        a0->print();
        ListNode *result = solution.swapPairs2_1(a0);
        result->print();

        return 0;
    }
}