//freopen("input.txt", "r", stdin);
//2096kb 4ms
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

int arr[102][102];
bool visit[102];
int Parr[102][102];
int N;
int cur;
void dfs(int st)
{
    rep1(i, N)
    {
        if (i == st)
            continue;
        if (arr[st][i] && !visit[i])
        {
            Parr[cur][i] = 1;
            visit[i] = true;
            dfs(i);
        }
    }
}

void dfsstart(int start)
{
    cur = start;
    dfs(start);
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    rep1(i, N)
    {
        rep1(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    rep1(i, N)
    {
        memset(visit, 0, sizeof(visit));
        dfsstart(i);
    }

    rep1(i, N)
    {
        rep1(j, N)
        {
            printf("%d ", Parr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
