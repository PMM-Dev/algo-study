//freopen("input.txt", "r", stdin);
//7528kb 76ms
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

int N, M;
vector<pii> graph[1001];
int par[1001];
int dist[1001];
bool visited[1001][1001];

//https://4legs-study.tistory.com/102
//MST가 아닌 반례

void dijkstra(int start)
{

    priority_queue<pii> pq;

    pq.push({0, start});
    dist[start] = 0;
    par[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().F;
        int cur = pq.top().S;

        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;

            if (dist[next] > cost + graph[cur][i].second)
            {
                dist[next] = cost + graph[cur][i].second;
                pq.push({-dist[next], next});
                par[next] = cur;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b, c;
    vector<pii> ansvec;

    scanf("%d %d", &N, &M);

    rep1(i, N)
    {
        dist[i] = INF;
    }

    rep(i, M)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    dijkstra(1);

    for (int i = 2; i <= N; i++)
    {
        int tmp = i;
        while (tmp != 1)
        {
            if (!visited[tmp][par[tmp]])
            {
                visited[tmp][par[tmp]] = true;
                ansvec.push_back({tmp, par[tmp]});
            }
            tmp = par[tmp];
        }
    }

    printf("%d\n", ansvec.size());

    rep(i, ansvec.size())
    {
        printf("%d %d\n", ansvec[i].F, ansvec[i].S);
    }

    return 0;
}
