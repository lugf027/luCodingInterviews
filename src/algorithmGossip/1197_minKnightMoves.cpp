/*************************************************************
 * Name     : 1197_minKnightMoves
 * Title    : 1197. 进击的骑士
 * Author   : lugf027 19:22 2021/1/19.
 * Describe :
 * 一个坐标可以从 -infinity 延伸到 +infinity 的 无限大的 棋盘上，你的 骑士 驻扎在坐标为 [0, 0] 的方格里。
 * 现在，骑士需要前去征服坐标为 [x, y] 的部落，请你为他规划路线。
 * 最后返回所需的最小移动次数即可。本题确保答案是一定存在的。
 *************************************************************/

#include "util.h"

namespace minKnightMoves {

    class Solution {
    private:
        vector<vector<int>> stepNear = {{0, 3, 2, 3, 2, 3},
                                        {3, 2, 1, 2, 3, 4},
                                        {2, 1, 4, 3, 2, 3},
                                        {3, 2, 3, 2, 3, 4},
                                        {2, 3, 2, 3, 4, 3},
                                        {3, 4, 3, 4, 3, 4}};

    public:
        int minKnightMoves(int x, int y) {
            x = abs(x);
            y = abs(y);
            int stepNum = 0;
            while (x > 5 || y > 5) {
                if (x > y) {
                    x -= 2;
                    y = y < 1 ? y + 1 : y - 1;
                } else {
                    y -= 2;
                    x = x < 1 ? x + 1 : x - 1;
                }
                ++stepNum;
            }
            return stepNum + stepNear[x][y];
        }
    };

}
