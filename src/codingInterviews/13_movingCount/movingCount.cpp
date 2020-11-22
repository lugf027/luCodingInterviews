/********************************************
* movingCount.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 * 1 <= n,m <= 100
 * 0 <= k <= 20
 */

#include <cstdlib>
#include <vector>

using namespace std;

namespace movingCount{

    class Solution {
    public:
        int m, n, k;
        bool **visited;

        /**
         * 1. dfs 广度优先搜索
         * 0 ms	6.6 MB
         * @param m
         * @param n
         * @param k
         * @return
         */
        int movingCount(int m, int n, int k) {
            this->m = m;
            this->n = n;
            this->k = k;
            this->visited = (bool **) malloc(sizeof(bool *) * m);
            for (int i = 0; i < m; i++)
                this->visited[i] = (bool *) malloc(sizeof(bool) * n);

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    visited[i][j] = false;
                }
            }

            return dfs(0, 0, 0, 0);
        }

    private:
        /**
         * 1. dfs
         * @param i 二维矩阵下标
         * @param j 二维矩阵下标
         * @param si 二维矩阵下标 i 数位和
         * @param sj 二维矩阵下标 j 数位和
         * @return
         */
        int dfs(int i, int j, int si, int sj) {
            if (i >= m || j >= n ||
                k < si + sj ||
                visited[i][j])
                return 0;

            visited[i][j] = true;

            return 1 +
                   dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj) +
                   dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8);
        }

        /**
         * 2.计算数位和
         * @param x
         * @return
         */
        int calNum(int x) {
            int res = 0;
            for (; x; x /= 10) {
                res += x % 10;
            }
            return res;
        }

    public:
        /**
         * 2.递推，不知道为什么运行很慢
         * 执行用时： 8 ms , 在所有 C++ 提交中击败了 27.82% 的用户
         * 内存消耗： 6.7 MB , 在所有 C++ 提交中击败了 61.36% 的用户
         * @param m
         * @param n
         * @param k
         * @return
         */
        int movingCount1(int m, int n, int k) {
            if (!k) return 1;  // k == 0

            vector<vector<bool>> visited1(m, vector<bool>(n, false));
            int ret = 1;
            visited1[0][0] = true;

            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if((i==0 && j==0) || calNum(i)+calNum(j) > k)
                        continue;

                    if(i >= 1) visited1[i][j] = visited1[i][j] || visited1[i - 1][j];
                    if(j >= 1) visited1[i][j] = visited1[i][j] || visited1[i][j - 1];
                    ret += visited1[i][j];
                }
            }

            return ret;
        }
    };

}
