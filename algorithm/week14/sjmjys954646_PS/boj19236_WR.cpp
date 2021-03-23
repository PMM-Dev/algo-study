//freopen("input.txt", "r", stdin);
//2028kb 4ms
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

int dirX[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dirY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

vector<vector<pii>> vec(4); // num dir
pii sharkPos;
int sharkDir;

pii findFish(int index)
{
    rep(i, 4)
    {
        rep(j, 4)
        {
            if (vec[i][j].F == index)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int Recur()
{
    int tot = 0;
    int ret = -INF;
    rep1(i, 16)
    {
        pii fishPos = findFish(i);
        if (fishPos.F == -1)
            continue;
        int fishdir = vec[fishPos.F][fishPos.S].S;
        int mvfishdir = fishdir;
        int k = 0;

        while (true)
        {
            if (mvfishdir == 8)
                mvfishdir = 0;

            if (k > 10)
                break;

            int nextPosY = fishPos.F + dirY[mvfishdir];
            int nextPosX = fishPos.S + dirX[mvfishdir];
            if (nextPosY < 0 || nextPosY > 3 || nextPosX < 0 || nextPosX > 3)
            {
                mvfishdir++;
                k++;
                continue;
            }
            if (nextPosY == sharkPos.F && nextPosX == sharkPos.S)
            {
                mvfishdir++;
                k++;
                continue;
            }

            pii tmp = vec[nextPosY][nextPosX];
            vec[nextPosY][nextPosX] = {i, mvfishdir};
            vec[fishPos.F][fishPos.S] = tmp;
            break;
        }
    }

    vector<pii> goalFish;
    int curSharkY = sharkPos.F;
    int curSharkX = sharkPos.S;
    for (int i = 1; i <= 3; i++)
    {
        int nextPosMoveY = curSharkY + i * dirY[sharkDir];
        int nextPosMoveX = curSharkX + i * dirX[sharkDir];
        if (nextPosMoveY < 0 || nextPosMoveY > 3 || nextPosMoveX < 0 || nextPosMoveX > 3)
            continue;

        goalFish.push_back({nextPosMoveY, nextPosMoveX});
    }

    if (goalFish.size() == 0)
        return 0;

    vector<vector<pii>> curvec = vec;

    for (int i = 0; i < goalFish.size(); i++)
    {
        int nextSharkMoveY = goalFish[i].F;
        int nextSharkMoveX = goalFish[i].S;

        sharkDir = vec[nextSharkMoveY][nextSharkMoveX].S;
        sharkPos = {nextSharkMoveY, nextSharkMoveX};
        int dieFishNum = vec[nextSharkMoveY][nextSharkMoveX].F;
        vec[nextSharkMoveY][nextSharkMoveX] = {0, 0};

        tot = dieFishNum + Recur();
        ret = max(tot, ret);
        tot -= dieFishNum;
        vec = curvec;
    }

    return ret;
}

int main()
{

    int a, b;

    rep(i, 4)
    {
        vec[i].resize(4);
    }

    rep(i, 4)
    {
        rep(j, 4)
        {
            scanf("%d %d", &a, &b);
            vec[i][j] = {a, b - 1};
        }
    }

    sharkPos = {0, 0};
    sharkDir = vec[0][0].S;
    int firstdie = vec[0][0].F;
    vec[0][0] = {0, 0};

    int ans = Recur();

    printf("%d", ans + firstdie);

    return 0;
}