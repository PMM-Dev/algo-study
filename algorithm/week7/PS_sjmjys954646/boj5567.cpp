//2148kb 0ms
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

int N, M;
vector<vi> graph;
W bool visit[503];
int ans = 0;

void bfs()
{
    queue<pii> q;
    q.push({1, 0});
    visit[1] = true;

    while (!q.empty())
    {
        int cur = q.front().F;
        int depth = q.front().S;
        q.pop();

        if (depth > 2)
            continue;

        ans++;
        rep(i, graph[cur].size())
        {
            int next = graph[cur][i];
            if (visit[next] == 1)
                continue;
            visit[next] = true;
            q.push({next, depth + 1});
        }
    }
}

int main()
{
    memset(visit, 0, sizeof(visit));
    freopen("input.txt", "r", stdin);

    graph.resize(503);

    scanf("%d", &N);
    scanf("%d", &M);

    rep(i, M)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs();

    printf("%d", ans - 1);

    return 0;
}
