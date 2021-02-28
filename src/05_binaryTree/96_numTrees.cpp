/*************************************************************
 * Name     : 96_numTrees
 * Title    : 96. 不同的二叉搜索树
 * Author   : lugf027 17:45 2021/2/26.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace numTrees {
    class Solution {
    public:
        int numTrees(int n) {
            vector<int> G(n + 1, 0);
            G[0] = 1;
            G[1] = 1;

            for (int i = 2; i <= n; ++i) {
                for (int j = 1; j <= i; ++j) {
                    G[i] += G[j - 1] * G[i - j];
                }
            }

            return G[n];
        }
    };
}
