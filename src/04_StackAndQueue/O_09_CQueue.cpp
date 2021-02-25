/*************************************************************
 * Name     : O_09_CQueue
 * Title    : 剑指 Offer 09. 用两个栈实现队列
 * Author   : lugf027 20:00 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace CQueue {
    class CQueue {
    private:
        stack<int> stackIn, stackOut;

    public:
        CQueue() {

        }

        void appendTail(int value) {
            stackIn.push(value);
        }

        int deleteHead() {
            if (stackOut.empty()) {
                while (!stackIn.empty()) {
                    stackOut.push(stackIn.top());
                    stackIn.pop();
                }
            }
            if(stackOut.empty())
                return -1;
            else{
                int itemDelete = stackOut.top();
                stackOut.pop();
                return itemDelete;
            }
        }
    };

}
