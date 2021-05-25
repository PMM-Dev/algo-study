//freopen("input.txt", "r", stdin);
//MEMORY : 2036kb
//TIME : 456ms
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

int N, L, R;
int arr[51][51];
int ans = 0;
bool visited[51][51];
int dX[4] = {0, 1, 0, -1};
int dY[4] = {1, 0, -1, 0};
vector<pii> group;

void bfs(int startY, int startX)
{
    queue<pii> q;
    visited[startY][startX] = true;
    q.push({startY, startX});
    group.pb({startY, startX});

    while (!q.empty())
    {
        int curY = q.front().F;
        int curX = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nY = curY + dY[i];
            int nX = curX + dX[i];

            if (nX < 0 || nY < 0 || nX >= N || nY >= N)
                continue;
            if (visited[nY][nX] == true)
                continue;

            int dif = abs(arr[curY][curX] - arr[nY][nX]);
            if (dif < L || R < dif)
                continue;

            q.push({nY, nX});
            group.pb({nY, nX});
            visited[nY][nX] = true;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &L, &R);

    rep(i, N)
    {
        rep(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    while (true)
    {
        int groupnum = 0;
        memset(visited, 0, sizeof(visited));

        rep(i, N)
        {
            rep(j, N)
            {
                if (!visited[i][j])
                {
                    bfs(i, j);
                    if (group.size() != 1)
                    {
                        int total = 0;
                        for (int i = 0; i < group.size(); i++)
                        {
                            total += arr[group[i].F][group[i].S];
                        }
                        int pop = total / group.size();
                        for (int i = 0; i < group.size(); i++)
                        {
                            arr[group[i].F][group[i].S] = pop;
                        }
                        groupnum++;
                    }

                    group.clear();
                }
            }
        }
        //DEBUG
        // rep(i, N)
        // {
        //    rep(j, N)
        //    {
        //       cout << arr[i][j] << " ";
        //    }
        //    cout << "\n";
        // }

        if (groupnum == 0)
            break;

        ans++;
    }

    printf("%d", ans);

    return 0;
}
