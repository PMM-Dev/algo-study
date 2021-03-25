// 청소년 상어
// https://www.acmicpc.net/problem/19236
// Memory	:  2016     KB
// Time		:  0        ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Fish {
public:
    int idx, dir;
    int x;
    int y;
};

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int board[4][4];
vector<Fish> fishes;
Fish shark;
int maxVal = 0;

void swapFish(Fish& fish1, Fish& fish2) {
    swap(fish1.dir, fish2.dir);
    swap(fish1.idx, fish2.idx);
}

void input() {
    fishes = vector<Fish>(17);
    for (auto i = 0; i < 4; ++i) {
        for (auto j = 0; j < 4; ++j) {
            auto fish = Fish();
            cin >> fish.idx >> fish.dir;
            --fish.dir;
            fish.x = j;
            fish.y = i;
            board[i][j] = fish.idx - 1;
            fishes[fish.idx - 1] = fish;
        }
    }
    shark = Fish();
    shark.dir = fishes[board[0][0]].dir;
    shark.x = 0;
    shark.y = 0;
    shark.idx = 16;
    fishes[16] = shark;
    board[0][0] = shark.idx;
}

void copyBoard(int board[4][4], int copiedBoard[4][4]) {
    copy(&board[0][0], &board[0][0] + 4 * 4, &copiedBoard[0][0]);
}

void copyFishes(vector<Fish> &fishes1, vector<Fish> &fishes2) {
    copy(fishes1.begin(), fishes1.end(), fishes2.begin());
}

bool isMovable(int board[4][4], vector<Fish>& fishes, Fish& fish) {
    auto destX = fish.x + dx[fish.dir], destY = fish.y + dy[fish.dir];
    if (destX < 0 || destX >= 4 || destY < 0 || destY >= 4) {
        return false;
    }
    else if (fishes[board[destY][destX]].idx > 15) {
        return false;
    }
    return true;
}

bool isSharkMovable(int board[4][4], vector<Fish>& fishes, int val) {
    auto destX = fishes[16].x, destY = fishes[16].y;
    while (val--) {
        destX += dx[fishes[16].dir];
        destY += dy[fishes[16].dir];
    }

    if (destX < 0 || destX >= 4 || destY < 0 || destY >= 4) {
        return false;
    }
    else if (fishes[board[destY][destX]].idx < 0) {
        return false;
    }

    return true;
}

void move(int board[4][4], vector<Fish>& fishes, Fish& fish) {
    auto destX = fish.x + dx[fish.dir], destY = fish.y + dy[fish.dir];
    auto dest = fishes[board[destY][destX]];
    if (dest.idx != -1) {
        swapFish(fish, dest);
        swap(board[fish.y][fish.x], board[destY][destX]);
    }
    else {
        fishes[board[fish.y][fish.x]].idx = -1;
        dest = fish;
    }
    fish.x = destX;
    fish.y = destY;
}

void sharkMove(int board[4][4], vector<Fish>& fishes, int val) {
    auto destX = fishes[16].x, destY = fishes[16].y;
    while (val--) {
        destX += dx[fishes[16].dir];
        destY += dy[fishes[16].dir];
    }
    cout << fishes[board[destY][destX]].idx << endl;
    fishes[16].idx += fishes[board[destY][destX]].idx;
    fishes[16].x = destX;
    fishes[16].y = destY;
    fishes[board[destX][destY]].idx = -1;
}

void solve(int board[4][4], vector<Fish>& fishes, int sharkX, int sharkY) {
    auto i = 0;
    while (i < 16) {
        auto fish = fishes[i++];
        if (fish.idx == -1)
            continue;
        while (!isMovable(board, fishes, fish))
            fish.dir = (fish.dir + 1) % 8;
        move(board, fishes, fish);
    }

    auto val = 3;
    while (val--) {
        if (isSharkMovable(board, fishes, maxVal)) {
            sharkMove(board, fishes, maxVal);
            if (fishes[16].idx > maxVal) {
                maxVal = fishes[16].idx;
            }
            int copiedBoard[4][4];
            copyBoard(board, copiedBoard);
            vector<Fish> copiedFishes = vector<Fish>(17);
            copyFishes(fishes, copiedFishes);
            solve(copiedBoard, copiedFishes, fishes[16].x, fishes[16].y);
        }
        else {
            return;
        }
    }
}

int main() {
    input();
    int copiedBoard[4][4];
    copyBoard(board, copiedBoard);
    vector<Fish> copiedFishes = vector<Fish>(17);
    copyFishes(fishes, copiedFishes);
    solve(copiedBoard, copiedFishes, fishes[16].x, fishes[16].y);
    cout << maxVal - 16 << "\n";
    return 0;
}