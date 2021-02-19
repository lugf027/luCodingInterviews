/*************************************************************
 * Name     : util
 * Title    : 
 * Author   : lugf027 15:54 2021/1/14.
 * Describe : 
 *************************************************************/

#ifndef CODINGINTERVIEWS_UTIL_H
#define CODINGINTERVIEWS_UTIL_H

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //CODINGINTERVIEWS_UTIL_H
