/********************************************
* getKthFromEnd.cpp                              *
* Created by lugf027 on 2020/11/22.            *
* Github: https://github.com/lugf027        *
*********************************************/

namespace getKthFromEnd {

    struct ListNode {
        int val;
        ListNode* next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    /**
     * 俩指针往前走
     */
    class Solution {
    public:
        ListNode* getKthFromEnd(ListNode* head, int k) {
            ListNode* list1 = head;
            while (k > 0) {
                if (list1 != nullptr)
                    list1 = list1->next;
                else
                    return nullptr;
                k--;
            }

            ListNode* list2 = head;
            while (list1 != nullptr) {
                list1 = list1->next;
                list2 = list2->next;
            }
            return list2;
        }
    };
}
