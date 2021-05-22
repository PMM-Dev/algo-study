// 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779
// Memory	:   3628    KB
// Time		:   100      ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> nodes[1001];
int dist[1001];
int visited[100001];

int n, m, src, dest;

void input()
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int s = 0, d = 0, w = 0;
        cin >> s >> d >> w;
        nodes[s].push_back(make_pair(d, w));
    }
    cin >> src >> dest;
}

void solve() {
    for (int i = 1; i <= n; ++i)
        dist[i] = 123456789;

    priority_queue<pair<int, int>> pq = priority_queue<pair<int, int>>();

    pq.push(make_pair(src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        int node = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        for (int i = 0; i < nodes[node].size(); ++i) {
            int nextNode = nodes[node][i].first;
            int nextCost = cost + nodes[node][i].second;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                visited[nextNode] = node;
                pq.push(make_pair(nextNode, -nextCost));
            }
        }
    }
    cout << dist[dest] << "\n";

    vector<int> routes;
    int back = dest;
    while (back) {
        routes.push_back(back);
        back = visited[back];
    }

    cout << routes.size() << "\n";
    for (int i = routes.size() - 1; i >= 0; --i) {
        cout << routes[i] << " ";
    }
}

int main() {
    input();
    solve();
    return 0;
}
