/********************************************
* islandPerimeter.cpp                              *
* Created by lugf027 on 2020/10/30.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 463. 岛屿的周长
/// 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
/// 网格中的格子水平和垂直方向相连（对角线方向不相连）。
/// 整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
/// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
/// 格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

#include <vector>

using namespace std;

namespace islandPerimeter {
    /**
     * 遍历陆地的四周
     * 时间复杂度：O(nm)
     * 空间复杂度：O(1)
     */
    class Solution {
    public:
        int islandPerimeter(vector<vector<int>> &grid) {
            if (grid.empty()) return 0;

            int m = grid.size();
            int n = grid.at(0).size();
            int res = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j]) {
                        if (i == 0 || !grid[i - 1][j]) ++res;
                        if (i == m - 1 || !grid[i + 1][j]) ++res;
                        if (j == 0 || !grid[i][j - 1]) ++res;
                        if (j == n - 1 || !grid[i][j + 1]) ++res;

//                        if(i>0){
//                            if(! grid[i-1][j]) ++res;
//                        }else
//                            ++res;
//
//                        if(i < m-1)   {
//                            if(! grid[i+1][j]) ++res;
//                        }
//                        else
//                            ++res;
//
//                        if(j > 0){
//                            if(!grid[i][j-1]) ++res;
//                        }else
//                            ++res;
//
//                        if(j<n-1){
//                            if(!grid[i][j+1]) ++res;
//                        }else
//                            ++res;
                    }
                }
            }
            return res;
        }
    };


    /**
     * dfs
     */
    class Solution1 {
        constexpr static int dx[4] = {0, 1, 0, -1};
        constexpr static int dy[4] = {1, 0, -1, 0};
    public:
        int dfs(int x, int y, vector<vector<int>> &grid, int n, int m) {
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
                return 1;
            }
            if (grid[x][y] == 2) {
                return 0;
            }
            grid[x][y] = 2;
            int res = 0;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                res += dfs(tx, ty, grid, n, m);
            }
            return res;
        }

        int islandPerimeter(vector<vector<int>> &grid) {
            int n = grid.size(), m = grid[0].size();
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1) {
                        ans += dfs(i, j, grid, n, m);
                    }
                }
            }
            return ans;
        }
    };
}
