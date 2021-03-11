/*************************************************************
 * Name     : util
 * Title    : 
 * Author   : lugf027 12:13 2021/2/28.
 * Describe : 
 *************************************************************/

#ifndef CODINGINTERVIEWS_UTIL_H
#define CODINGINTERVIEWS_UTIL_H

#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#endif //CODINGINTERVIEWS_UTIL_H
