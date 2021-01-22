/*************************************************************
 * Name     : 23_mergeKLists
 * Title    : 23. 合并K个升序链表
 * Author   : lugf027 16:08 2021/1/14.
 * Describe :
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *************************************************************/

#include "util.h"

namespace mergeKLists {

/**
 * 遍历、顺序依次合并
 */
    class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            auto *resPre = new ListNode(-1);
            ListNode *resPreCp = resPre;

            while (l1 && l2) {
                if (l1->val < l2->val) {
                    resPre->next = l1;
                    l1 = l1->next;
                } else {
                    resPre->next = l2;
                    l2 = l2->next;
                }
                resPre = resPre->next;
            }
            resPre->next = l1 ? l1 : l2;

            resPre = resPreCp->next;
            delete resPreCp;
            return resPre;

            // return resPreCp->next;
        }

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            ListNode *res = nullptr;
            for (auto *v:lists) {
                res = mergeTwoLists(res, v);
            }
            return res;
        }
    };

/**
 * 小优化、分治合并
 */
    class Solution1 {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            auto *resPre = new ListNode(-1);
            ListNode *resPreCp = resPre;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    resPre->next = l1;
                    l1 = l1->next;
                } else {
                    resPre->next = l2;
                    l2 = l2->next;
                }
                resPre = resPre->next;
            }
            resPre->next = l1 ? l1 : l2;

            resPre = resPreCp->next;
            delete resPreCp;
            return resPre;

            // return resPreCp->next;
        }

        ListNode *mergeKListsAux(vector<ListNode *> &lists, int l, int r) {
            if (l == r) return lists[l];
            if (l > r) return nullptr;
            int mid = ((r - l) >> 1) + l;
            return mergeTwoLists(mergeKListsAux(lists, l, mid), mergeKListsAux(lists, mid + 1, r));

        }

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            return mergeKListsAux(lists, 0, lists.size() - 1);
        }
    };

/**
 * 优先队列 (《STL源码剖析》)
 */
    class Solution2 {
    public:
        struct Status {
            int val;
            ListNode *ptr;

            bool operator<(const Status &rhs) const {
                return val > rhs.val;
            }
        };

        // #include <queue>
        priority_queue<Status> q;

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            for (auto node: lists) {
                if (node) q.push({node->val, node});
            }

            auto *resPre = new ListNode(-1);
            ListNode *resPreCp = resPre;

            while (!q.empty()) {
                auto f = q.top();
                q.pop();
                resPre->next = f.ptr;
                resPre = resPre->next;
                if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
            }
            return resPreCp->next;
        }
    };

}
