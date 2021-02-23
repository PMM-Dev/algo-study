//6132kb 84ms
//COMMENT
/*
초기에 자르는 지점 중심을 불순물 기준으로 잡았더니
최종적으로 짤랐을때 최종모양은 같지만 순서만 달라지는 중복되는 현상이 발견됨
그래서 이를 해결하기 위해 아차원벡터를 map에도 넣어봤지만 WC
*/
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

int N;
int arr[21][21];
int ans = 0;
bool visit[21][21];

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool bfs(int x, int y)
{
    int jewel = 0;
    int bulsun = 0;
    queue<pii> q;

    q.push({x, y});
    visit[y][x] = true;
    if (arr[y][x] == 1)
        bulsun++;
    else if (arr[y][x] == 2)
        jewel++;

    while (!q.empty())
    {
        int tmpX = q.front().F;
        int tmpY = q.front().S;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nX = tmpX + dX[i];
            int nY = tmpY + dY[i];

            if (nX < 0 || nY < 0 || nX >= N || nY >= N)
                continue;

            if (visit[nY][nX])
                continue;

            q.push({nX, nY});
            visit[nY][nX] = true;
            if (arr[nY][nX] == 1)
                bulsun++;
            else if (arr[nY][nX] == 2)
                jewel++;
        }
    }
    if (bulsun > 0)
        return false;

    if (jewel >= 2 || jewel == 0)
        return false;
    return true;
}

bool judge()
{
    memset(visit, 0, sizeof(visit));
    bool chk = true;

    rep(i, N)
    {
        rep(j, N)
        {
            if (arr[i][j] == -1)
                visit[i][j] = true;
        }
    }

    rep(i, N)
    {
        rep(j, N)
        {
            if (visit[i][j])
                continue;

            chk = bfs(j, i);
            if (chk == false)
            {
                i = N;
                j = N;
            }
        }
    }

    return chk;
}

void cut(int startX, int endX, int startY, int endY, int dir, int depth) //1세로 2가로
{
    //DEBUG
    // cout << startX << " " << endX << " " << startY << " " << endY << " "
    //      << "\n";
    // rep(i, N)
    // {
    //     rep(j, N)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // cout << "\n";
    if (startX < 0 || endX >= N || startY < 0 || endY >= N)
        return;

    int tmp[21][21]; //현재상태 저장
    int after[21][21];
    vector<pii> hubo; // 방향 + 위치

    if (dir == 0 || dir == 2)
    {
        for (int i = startY + 1; i <= endY - 1; i++) // 가로로 그을수 있는 경우
        {
            bool pos = true;
            int bulsun = 0;
            for (int j = startX; j <= endX; j++)
            {
                if (arr[i][j] == 2)
                    pos = false;
                if (arr[i][j] == 1)
                    bulsun++;
            }
            if (!pos)
                continue;
            if (bulsun > 0)
                hubo.pb({2, i});
        }
    }
    if (dir == 0 || dir == 1)
    {
        for (int i = startX + 1; i <= endX - 1; i++) // 세로로 그을수 있는 경우
        {
            bool pos = true;
            int bulsun = 0;
            for (int j = startY; j <= endY; j++)
            {
                if (arr[j][i] == 2)
                    pos = false;
                if (arr[j][i] == 1)
                    bulsun++;
            }
            if (!pos)
                continue;
            if (bulsun > 0)
                hubo.pb({1, i});
        }
    }

    if (hubo.empty())
    {
        return;
    }

    memcpy(tmp, arr, sizeof(arr));

    for (int k = 0; k < hubo.size(); k++)
    {
        int huboDir = hubo[k].F;
        int huboPos = hubo[k].S;
        bool check = true;

        if (huboDir == 1) //세로
        {
            memcpy(after, tmp, sizeof(tmp));
            for (int i = startY; i <= endY; i++) //세로로 그음
            {
                after[i][huboPos] = -1;
            }
            memcpy(arr, after, sizeof(after));
            cut(startX, huboPos - 1, startY, endY, 2, depth + 1); //다음은 가로처리
            cut(huboPos + 1, endX, startY, endY, 2, depth + 1);
        }
        else if (huboDir == 2) //가로
        {
            memcpy(after, tmp, sizeof(tmp));
            for (int i = startX; i <= endX; i++) //가로로 그음
            {
                after[huboPos][i] = -1;
            }
            memcpy(arr, after, sizeof(after));
            cut(startX, endX, startY, huboPos - 1, 1, depth + 1); //다음은 세로처리
            cut(startX, endX, huboPos + 1, endY, 1, depth + 1);
        }

        // //DEBUG
        // rep(i, N)
        // {
        //     rep(j, N)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        // cout << "\n";
        if (depth == 0)
        {
            if (judge())
                ans++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    rep(i, N)
    {
        rep(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cut(0, N - 1, 0, N - 1, 0, 0);

    if (ans == 0)
        ans = -1;
    printf("%d", ans);

    return 0;
}
