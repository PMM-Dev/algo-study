//freopen("input.txt", "r", stdin);
//2288kb 12ms
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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[150][150];
int dist[150][150];
int dp[150][150];
int N;

void dijkstra()
{

    priority_queue<pair<int, pii>> pq;

    pq.push({-dp[0][0], {0, 0}});
    dist[0][0] = dp[0][0];

    while (!pq.empty())
    {
        int cost = -pq.top().F;
        int curX = pq.top().S.F;
        int curY = pq.top().S.S;

        pq.pop();

        if (curX == N - 1 && curY == N - 1)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if (nX < 0 || nY < 0 || nX >= N || nY >= N)
                continue;

            if (dist[nY][nX] > dp[nY][nX] + cost)
            {
                dist[nY][nX] = dp[nY][nX] + cost;
                pq.push({-dist[nY][nX], {nX, nY}});
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int cnt = 1;

    while (true)
    {
        scanf("%d", &N);

        if (N == 0)
            break;

        memset(dp, 0, sizeof(dp));

        rep(i, N)
        {
            rep(j, N)
            {
                scanf("%d", &dp[i][j]);
                dist[i][j] = INF;
            }
        }

        dijkstra();

        printf("Problem %d: %d\n", cnt++, dist[N - 1][N - 1]);
    }

    return 0;
}
