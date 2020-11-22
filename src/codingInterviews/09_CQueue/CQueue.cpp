/********************************************
* CQueue.cpp                              *
* Created by lugf027 on 2020/10/13.            *
* Github: https://github.com/lugf027        *
*********************************************/

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <stack>

using namespace std;

namespace CQueue {

    class CQueue {
    public:
        CQueue() {

        }

        void appendTail(int value) {
            in.push(value);
        }

        int deleteHead() {
            if (out.empty()) {
                while ((int) in.size() > 0) {
                    out.push(in.top());
                    in.pop();
                }
            }
            if (out.empty()) {
                return -1;
            }
            else {
                int ret = out.top();
                out.pop();
                return ret;
            }
        }

    private:
        stack<int> in;
        stack<int> out;
    };

#include <iostream>

    class CQueueTest {
    public:
        static int test() {
            CQueue cQueue;
            cQueue.appendTail(0);
            cQueue.appendTail(1);
            cQueue.appendTail(2);
            cQueue.appendTail(3);
            cQueue.appendTail(4);
            cQueue.appendTail(5);
            cQueue.appendTail(6);

            int a0 = cQueue.deleteHead();
            int a1 = cQueue.deleteHead();
            int a2 = cQueue.deleteHead();
            int a3 = cQueue.deleteHead();
            int a4 = cQueue.deleteHead();
            int a5 = cQueue.deleteHead();
            int a6 = cQueue.deleteHead();

            printf("%d,%d,%d,%d,%d,%d,%d", a0, a1, a2, a3, a4, a5, a6);

            return 0;
        }
    };


}
