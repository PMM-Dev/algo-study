// 네트워크 복구
// https://www.acmicpc.net/problem/2211
// Memory	:   6548    KB
// Time		:   180     ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> nodes[1001];
int dist[1001];
int visited[1001];

int N, M;
int maxCpu = 0;

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        int s = 0, d = 0, w = 0;
        cin >> s >> d >> w;
        if (s > maxCpu)
            maxCpu = s;
        if (d > maxCpu)
            maxCpu = d;
        nodes[s].push_back(make_pair(d, w));
        nodes[d].push_back(make_pair(s, w));
    }
}

void solve() {
    for (int i = 1; i <= N; ++i)
        dist[i] = 123456789;

    priority_queue<pair<int, int>> pq = priority_queue<pair<int, int>>();

    pq.push(make_pair(1, 0));
    dist[1] = 0;

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

    cout << maxCpu - 1 << "\n";
    for (int i = 2; i <= N; ++i) {
        cout << i << " " << visited[i] << "\n";
    }
}

int main() {
    input();
    solve();
    return 0;
}
