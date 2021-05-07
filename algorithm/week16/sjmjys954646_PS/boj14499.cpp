//freopen("input.txt", "r", stdin);
//2020kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

int N, M, x, y, K;
int arr[30][30] = {
    0,
};
int dice[5] = {
    0,
};
int topdice = 0;
int posX[5] = {INF, 1, -1, 0, 0};
int posY[5] = {INF, 0, 0, -1, 1};

void roll(int order)
{
    int tmp;
    if (order == 4)
    {
        tmp = topdice;
        topdice = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[4];
        dice[4] = tmp;
    }
    else if (order == 3)
    {
        tmp = topdice;
        topdice = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[0];
        dice[0] = tmp;
    }
    else if (order == 2)
    {
        tmp = topdice;
        topdice = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = tmp;
    }
    else if (order == 1)
    {
        tmp = topdice;
        topdice = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = tmp;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int tmp;

    scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

    rep(i, N)
    {
        rep(j, M)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    rep(i, K)
    {
        scanf("%d", &tmp);

        int nX = x + posX[tmp];
        int nY = y + posY[tmp];

        if (nX < 0 || nY < 0 || nX >= M || nY >= N)
            continue;

        roll(tmp);

        if (arr[nY][nX] == 0)
        {
            arr[nY][nX] = dice[2];
        }
        else
        {
            dice[2] = arr[nY][nX];
            arr[nY][nX] = 0;
        }

        printf("%d\n", topdice);

        x = nX;
        y = nY;
    }

    return 0;
}
