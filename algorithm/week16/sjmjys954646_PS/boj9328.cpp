//freopen("input.txt", "r", stdin);
//2104kb 32ms
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

int h, w;
int arr[103][103];
int key[27] = {
    0,
};
int ans;
int visited[103][103];
int posX[4] = {1, -1, 0, 0};
int posY[4] = {0, 0, -1, 1};

void bfs()
{
    queue<pii> q;
    q.push({0, 0});

    while (!q.empty())
    {

        int curX = q.front().F;
        int curY = q.front().S;
        q.pop();

        // rep(i, h + 2)
        // {
        //     rep(j, w + 2)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << curY << " " << curX << "\n";

        for (int i = 0; i < 4; i++)
        {
            int nX = curX + posX[i];
            int nY = curY + posY[i];

            if (nY < 0 || nX < 0 || nY > h + 1 || nX > w + 1)
                continue;

            if (visited[nY][nX] == 1 || arr[nY][nX] == -1 || ((int)'A' <= arr[nY][nX] && (int)'Z' >= arr[nY][nX]))
                continue;

            visited[nY][nX] = 1;
            q.push({nX, nY});

            if (arr[nY][nX] == 1)
            {
                ans++;
                arr[nY][nX] = 0;
            }
            if ((int)'a' <= arr[nY][nX] && (int)'z' >= arr[nY][nX])
            {
                int f = arr[nY][nX] - (int)'a';
                arr[nY][nX] = 0;

                if (key[f] == 0)
                {
                    key[f] = 1;
                    rep(i, h + 1)
                    {
                        rep(j, w + 1)
                        {
                            if (arr[i][j] == f + 'A')
                                arr[i][j] = 0;
                        }
                    }
                }

                memset(visited, 0, sizeof(visited));
                while (!q.empty())
                    q.pop();
                q.push({nX, nY});
                break;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        memset(key, 0, sizeof(key));
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        scanf("%d %d", &h, &w);

        string tmp;
        rep(i, h)
        {
            cin >> tmp;
            rep(j, w)
            {
                if (tmp[j] == '*')
                    arr[i + 1][j + 1] = -1;
                else if (tmp[j] == '.')
                    arr[i + 1][j + 1] = 0;
                else if (tmp[j] == '$')
                    arr[i + 1][j + 1] = 1;
                else
                    arr[i + 1][j + 1] = (int)tmp[j];
            }
        }
        cin >> tmp;
        rep(t, tmp.size())
        {
            key[tmp[t] - 'a'] = 1;
            rep(i, h + 1)
            {
                rep(j, w + 1)
                {
                    if (arr[i][j] == (int)tmp[t] + 'A' - 'a')
                        arr[i][j] = 0;
                }
            }
        }

        bfs();

        printf("%d\n", ans);
    }

    return 0;
}
