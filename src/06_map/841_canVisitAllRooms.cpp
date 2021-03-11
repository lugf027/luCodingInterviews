/*************************************************************
 * Name     : 841_canVisitAllRooms
 * Title    : 
 * Author   : lugf027 12:31 2021/2/28.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace canVisitAllRooms {
    /**
     * 广度优先
     */
    class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>> &rooms) {
            if (rooms.empty()) return true;
            // 这里可以用unordered_set 表示已经访问的房间
            // 也可以用一个bool 数组
            unordered_set<int> visited;
            queue<int> roomsQueue;
            visited.insert(0);
            roomsQueue.push(0);
            while (!roomsQueue.empty()) {
                int roomNow = roomsQueue.front();
                roomsQueue.pop();
                for (auto room: rooms[roomNow]) {
                    if (visited.find(room) == visited.end()) {
                        visited.insert(room);
                        roomsQueue.push(room);
                    }
                }
            }
            return rooms.size() == visited.size();
        }
    };
    /**
     * 深度优先
     */
    class Solution1 {
    public:
        vector<bool> vis;
        int num;

        void dfs(vector<vector<int>>& rooms, int x) {
            vis[x] = true;
            num++;
            for (auto& it : rooms[x]) {
                if (!vis[it]) {
                    dfs(rooms, it);
                }
            }
        }

        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            num = 0;
            vis.resize(n);
            dfs(rooms, 0);
            return num == n;
        }
    };
}
