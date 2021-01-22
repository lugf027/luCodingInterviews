/*************************************************************
 * Name     : 1265_printLinkedListInReverse
 * Title    : 
 * Author   : lugf027 15:55 2021/1/20.
 * Describe : 
 *************************************************************/

class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode *getNext(); // return the next node.
};

namespace printLinkedListInReverse {
    class Solution {
    public:
        void printLinkedListInReverse(ImmutableListNode *head) {
            if (head) {
                printLinkedListInReverse(head->getNext());
                head->printValue();
            }
        }
    };
}
