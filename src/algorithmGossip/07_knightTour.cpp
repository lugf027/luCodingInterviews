/*************************************************************
 * Name     : 07_knightTour
 * Title    : 骑士走棋盘
 * Author   : lugf027 22:52 2021/1/17.
 * Describe :
 * 骑士旅游（Knight tour）在十八世纪初倍受数学家与拼图迷的注意。
 * 一个骑士在棋盘中，给予其一个初始位置，求其能否走完整个棋盘。
 * 骑士走法同中国象棋“马走日”；前进过程中，落足的地方不可再次落足。
 *************************************************************/

// 每次选择下一步能走的步数最少的位置

#include <iostream>
#include <vector>

using namespace std;

const int directionNum = 8;
vector<int> stepX = {-1, 1, 2, 2, 1, -1, -2, -2};
vector<int> stepY = {2, 2, 1, -1, -2, -2, -1, 1};

enum travelState {
    TRAVEL_NOT = 0,
    TRAVEL_YES = 1,
};

void printChessBoard(vector<vector<int>> chessBoard) {
    for (int i = 0; i < chessBoard.size(); ++i) {
        for (int j = 0; j < chessBoard[0].size(); ++j)
            cout << chessBoard[i][j] << ' ';
        cout << endl;
    }
}

int getNextStepMinNum(vector<vector<int>> chessBoard, int rowNow, int columnNow) {
    int stepNum = 0;
    for (int i = 0; i < directionNum; ++i) {
        if (rowNow + stepX[i] >= 0 && rowNow + stepX[i] < chessBoard.size() &&
            columnNow + stepY[i] >= 0 && columnNow + stepY[i] < chessBoard[0].size() &&
            chessBoard[rowNow + stepX[i]][columnNow + stepY[i]] == TRAVEL_NOT) {
            ++stepNum;
        }
    }
    return stepNum;
}

bool travel(vector<vector<int>> chessBoard, int startX, int startY) {
    if (chessBoard.empty()) return false;

    int stepTotalNum = chessBoard.size() * chessBoard[0].size();
    int xNow = startY;
    int yNow = startY;
    for (int stepI = 1; stepI < stepTotalNum; ++stepI) {
        cout << xNow << " " << yNow << endl;
        chessBoard[xNow][yNow] = TRAVEL_YES;
        if (!getNextStepMinNum(chessBoard, xNow, yNow)) return false;
        int stepMin = 9;
        int nextDirectionI = -1;
        for (int directionI = 0; directionI < directionNum; ++directionI) {

            if (xNow + stepX[directionI] >= 0 && xNow + stepX[directionI] < chessBoard.size() &&
                yNow + stepY[directionI] >= 0 && yNow + stepY[directionI] < chessBoard[0].size() &&
                chessBoard[xNow + stepX[directionI]][yNow + stepY[directionI]] == TRAVEL_NOT) {
                int stepNowMin = getNextStepMinNum(chessBoard, xNow + stepX[directionI], yNow + stepY[directionI]);
                if (stepNowMin < stepMin) {
                    stepMin = stepNowMin;
                    nextDirectionI = directionI;
                }
            }
        }
        xNow += stepX[nextDirectionI];
        yNow += stepY[nextDirectionI];
    }
    return true;
}

int main() {
    vector<vector<int>> chessBoard(directionNum, vector<int>(directionNum));
    int startX = 2;
    int startY = 2;
    if (travel(chessBoard, startX, startY)) {
        cout << "Success!" << endl;
    } else {
        cout << "Fail!" << endl;
    }
}
