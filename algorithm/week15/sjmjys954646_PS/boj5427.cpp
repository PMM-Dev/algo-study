//freopen("input.txt", "r", stdin);
//8940kb 112ms
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

char arr[1001][1001];
int w, h;
int board[1001][1001];
int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};
int sX, sY;

int bfs(int startY, int startX)
{
    int check = false;
    int ans;
    int sec = 0;
    queue<pair<pii, int>> q;
    q.push({{startY, startX}, 1});
    board[startY][startX] = 1;

    queue<pii> fq;

    rep(i, h)
    {
        rep(j, w)
        {
            if (board[i][j] == -1)
            {
                fq.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int curY = q.front().F.F;
        int curX = q.front().F.S;
        int sz = q.front().S;
        q.pop();

        if (sec < sz)
        {
            int turn = fq.size();
            for (int t = 0; t < turn; t++)
            {
                int curFX = fq.front().S;
                int curFY = fq.front().F;
                fq.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nX = curFX + dX[i];
                    int nY = curFY + dY[i];
                    if (nY < 0 || nY >= h || nX < 0 || nX >= w)
                        continue;

                    if (board[nY][nX] != 0)
                        continue;

                    fq.push({nY, nX});
                    board[nY][nX] = -1;
                }
            }
            sec++;
        }

        for (int i = 0; i < 4; i++)
        {
            int nX = curX + dX[i];
            int nY = curY + dY[i];

            if (nY < 0 || nY >= h || nX < 0 || nX >= w)
            {
                check = true;
                ans = sz;
                break;
            }

            if (board[nY][nX] != 0)
                continue;

            q.push({{nY, nX}, sz + 1});
            board[nY][nX] = sz + 1;
        }

        if (check)
            break;

        // rep(i, h)
        // {
        //     rep(j, w)
        //     {
        //         printf("%d", board[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    if (check)
        return ans;
    else
        return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int testcase;
    int startPointX, startPointY;

    scanf("%d", &testcase);

    while (testcase--)
    {
        memset(arr, 0, sizeof(arr));
        memset(board, 0, sizeof(board));
        string tmp;
        scanf("%d %d", &w, &h);
        rep(i, h)
        {
            cin >> tmp;
            rep(j, w)
            {
                arr[i][j] = tmp[j];
                if (arr[i][j] == '@')
                {
                    startPointX = j;
                    startPointY = i;
                }
                if (arr[i][j] == '#')
                {
                    board[i][j] = -5;
                }
                if (arr[i][j] == '*')
                {
                    board[i][j] = -1;
                }
            }
        }

        int ans = bfs(startPointY, startPointX);

        if (ans != -1)
            printf("%d\n", ans);
        else
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
