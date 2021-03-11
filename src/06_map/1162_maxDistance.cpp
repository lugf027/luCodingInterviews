/*************************************************************
 * Name     : 1162_maxDistance
 * Title    : 
 * Author   : lugf027 12:44 2021/2/28.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace maxDistance {
    class Solution {
    public:
        static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        static constexpr int MAX_N = 100 + 5;

        bool visited[MAX_N][MAX_N];

        struct Coordinate {
            int x, y, step;
        };

        int findNearestLand(int x, int y, vector<vector<int>> &grid) {
            memset(visited, 0, sizeof visited);
            queue<Coordinate> pathQueue;
            pathQueue.push({x, y, 0});
            visited[x][y] = 1;

            while (!pathQueue.empty()) {
                auto front = pathQueue.front();
                pathQueue.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = front.x + dx[i];
                    int ny = front.y + dy[i];
                    if (!(nx >= 0 && nx <= grid.size() - 1 && ny >= 0 && ny <= grid[0].size() - 1)) {
                        continue;
                    }
                    if (!visited[nx][ny]) {
                        pathQueue.push({nx, ny, front.step + 1});
                        visited[nx][ny] = 1;
                        if (grid[nx][ny]) {
                            return front.step + 1;
                        }
                    }
                }
            }
            return -1;
        }

        int maxDistance(vector<vector<int>> &grid) {
            int res = -1;

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (!grid[i][j]) {
                        res = max(res, findNearestLand(i, j, grid));
                    }
                }
            }

            return res;
        }
    };


    /**
     * 动态规划
     */
    class Solution10 {
    public:
        static constexpr int MAX_N = 100 + 5;
        static constexpr int MAX_HERE = int(1e6);
        int f[MAX_N][MAX_N];

        int maxDistance(vector<vector<int>> &grid) {
            int res = -1;

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    f[i][j] = (grid[i][j] ? 0 : MAX_HERE);
                }
            }

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j]) continue;

                    if (i - 1 >= 0) {
                        f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                    }
                    if (j - 1 >= 0) {
                        f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                    }
                }
            }

            for (int i = int(grid.size()) - 1; i >= 0; --i) {
                for (int j = int(grid[0].size()) - 1; j >= 0; --j) {
                    if (grid[i][j]) continue;

                    if (i + 1 < grid.size()) {
                        f[i][j] = min(f[i][j], f[i + 1][j] + 1);
                    }
                    if (j + 1 < grid[0].size()) {
                        f[i][j] = min(f[i][j], f[i][j + 1] + 1);
                    }
                }
            }

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (!grid[i][j]) {
                        res = max(res, f[i][j]);
                    }
                }
            }

            return res == MAX_HERE ? 0 : res;
        }
    };

}
