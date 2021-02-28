/*************************************************************
 * Name     : util
 * Title    : 
 * Author   : lugf027 20:11 2021/2/25.
 * Describe : 
 *************************************************************/

#ifndef CODINGINTERVIEWS_UTIL_H
#define CODINGINTERVIEWS_UTIL_H

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CODINGINTERVIEWS_UTIL_H
