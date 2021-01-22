/*************************************************************
 * Name     : ROAD5_maze
 * Title    : 老鼠走迷官（一）
 * Author   : lugf027 22:20 2021/1/17.
 * Describe :
 * 老鼠走迷宫是递回求解的基本题型，我们在二维阵列中使用WALL表示迷宫墙壁，使
 * 用1来表示老鼠的行走路径，试以程式求出由入口至出口的路径
 *************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int startI = 1, startJ = 1;  // 入口
int endI = 5, endJ = 5;      // 出口

enum Positions {
    ROAD = 0,
    WALL = 2,
    VISITED = 1,
};

/**
 * 打印地图
 * @param maze 
 * @param row
 * @param column
 */
void printMaze(vector<vector<int>> maze) {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[0].size(); ++j)
            cout << maze[i][j] << ' ';
        cout << endl;
    }
}

bool visit(vector<vector<int>> &maze, int posRow, int posCol) {
    maze[posRow][posCol] = VISITED;
    if (posRow == endI && posCol == endJ) return true;

    if (posRow > 0 && maze[posRow - 1][posCol] == ROAD) if (visit(maze, posRow - 1, posCol)) return true;
    if (posCol > 0 && maze[posRow][posCol - 1] == ROAD) if(visit(maze, posRow, posCol - 1)) return true;
    if (posRow < maze.size() && maze[posRow + 1][posCol] == ROAD) if(visit(maze, posRow + 1, posCol)) return true;
    if (posCol < maze[0].size() && maze[posRow][posCol + 1] == ROAD) if(visit(maze, posRow, posCol + 1)) return true;

    maze[posRow][posCol] = ROAD;
    return false;
}

int main() {
    vector<vector<int>> maze = {{WALL, WALL, WALL, WALL, WALL, WALL, WALL},
                                {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
                                {WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL},
                                {WALL, ROAD, ROAD, WALL, ROAD, WALL, WALL},
                                {WALL, WALL, ROAD, WALL, ROAD, WALL, WALL},
                                {WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
                                {WALL, WALL, WALL, WALL, WALL, WALL, WALL}};
    printMaze(maze);
    if (visit(maze, startI, startJ)) {
        cout << "\nSuccess!\n" << endl;
        printMaze(maze);
    } else {
        cout << "\nFail!" << endl;
    }

    return 0;
}
