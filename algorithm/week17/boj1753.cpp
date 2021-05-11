// 최단 경로
// https://www.acmicpc.net/problem/1753
// Memory	:  9064 KB
// Time		:  312  ms

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int V, E;
int K;
int dist[20001];
vector<pair<int, int>> graph[20001];

void input() {
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    fill_n(dist, 20001, 300001);
}

void solve() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, K));
    dist[K] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] < cost)
            continue;

        for (int i = 0; i < graph[v].size(); ++i) {
            int next = graph[v][i].first;
            int nextCost = cost + graph[v][i].second;
            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] > 300000)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    input();
    solve();
    return 0;
}
