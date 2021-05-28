// 唳餌煎
// https://www.acmicpc.net/problem/14890
// Memory	:   2080    KB
// Time		:   0     ms

#include <iostream>
#include <cmath>

using namespace std;

// 六六六六六
bool r[100];
bool c[100];

int N, L;
int board[100][100];
bool rBoard[100][100];
bool cBoard[100][100];

void input() {
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

bool check(int r, int c, int rDirection, int cDirection) {
    for (int i = 1; i <= L; ++i) {
        auto startR = r;
        auto startC = c;
        if (rDirection < 0)
            startR = r + 1;
        if (cDirection < 0)
            startC = c + 1;

        auto pointR = startR + rDirection * i;
        auto pointC = startC + cDirection * i;

        if (pointR < 0 || pointR >= N)
            return false;
        if (pointC < 0 || pointC >= N)
            return false;
        if (abs(board[pointR][pointC] - board[startR][startC]) != 1)
            return false;

        if (rDirection != 0) {
            if (!cBoard[pointR][pointC])
                cBoard[pointR][pointC] = true;
            else
                return false;
        }
        else {
            if (!rBoard[pointR][pointC])
                rBoard[pointR][pointC] = true;
            else
                return false;
        }
    }
    return true;
}

void solve() {
    for (int i = 0; i < N; ++i) {
        auto isPos = true;
        for (int j = 0; j < N - 1; ++j) {
            auto diff = board[i][j] - board[i][j + 1];
            if (diff != 0) {
                isPos = check(i, j, 0, diff / abs(diff));
                if (!isPos)
                    break;
            }
        }
        if (isPos)
            r[i] = true;
    }

    for (int j = 0; j < N; ++j) {
        auto isPos = true;
        for (int i = 0; i < N - 1; ++i) {
            auto diff = board[i][j] - board[i + 1][j];
            if (diff != 0) {
                isPos = check(i, j, diff / abs(diff), 0);
                if (!isPos)
                    break;
            }
        }
        if (isPos)
            c[j] = true;
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum = r[i] ? sum + 1 : sum;
        sum = c[i] ? sum + 1 : sum;
    }
    cout << sum << "\n";
}

int main() {
    input();
    solve();
    return 0;
}
