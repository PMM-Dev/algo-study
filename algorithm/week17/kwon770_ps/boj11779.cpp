// Memory : 6000 KB
// Time : 24 ms
#include <iostream>
#include <limits.h>
#include <queue>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

class Node {
public:
  int cost;
  int city;
};

struct cmp {
  bool operator()(Node a, Node b) { return a.cost > b.cost; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> bus(n + 1, vector<int>(n + 1, -1));
  For(i, 0, m) {
    int f, t, e;
    cin >> f >> t >> e;
    if (bus[f][t] != -1 && bus[f][t] <= e)
      continue;

    bus[f][t] = e;
  }
  int origin, destination;
  cin >> origin >> destination;

  priority_queue<Node, vector<Node>, cmp> pq;
  pq.push(Node{0, origin});
  vector<int> dist(n + 1, INT_MAX);
  vector<int> back(n + 1);
  dist[origin] = 0;
  while (!pq.empty()) {
    int cost = pq.top().cost;
    int city = pq.top().city;
    pq.pop();

    if (dist[city] < cost)
      continue;

    for (int i = 1; i <= n; i++) {
      if (bus[city][i] == -1)
        continue;

      int nCost = cost + bus[city][i];
      if (dist[i] <= nCost)
        continue;

      dist[i] = nCost;
      back[i] = city;
      pq.push(Node{nCost, i});
    }
  }

  vector<int> backtracking = {destination};
  int idx = destination;
  while (idx != origin) {
    backtracking.push_back(back[idx]);
    idx = back[idx];
  }

  cout << dist[destination] << endl;
  cout << backtracking.size() << endl;
  while (!backtracking.empty()) {
    cout << backtracking.back() << " ";
    backtracking.pop_back();
  }

  return 0;
}
