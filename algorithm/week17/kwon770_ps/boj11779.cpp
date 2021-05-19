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
  vector<int> way;
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
    bus[f][t] = e;
  }
  int origin, destination;
  cin >> origin >> destination;

  priority_queue<Node, vector<Node>, cmp> pq;
  pq.push(Node{0, origin, vector<int>()});
  vector<int> dist(n + 1, INT_MAX);
  vector<int> ansWay;
  while (!pq.empty()) {
    int cost = pq.top().cost;
    int city = pq.top().city;
    vector<int> way = pq.top().way;
    pq.pop();

    if (dist[city] < cost)
      continue;

    for (int i = 1; i <= sz(bus[city]); i++) {
      if (bus[city][i] == -1)
        continue;

      int nCost = cost + bus[city][i];
      if (dist[i] <= nCost)
        continue;

      dist[i] = nCost;
      way.push_back(i);
      pq.push(Node{nCost, i, way});

      if (i == destination)
        ansWay = way;
      way.pop_back();
    }
  }

  cout << dist[destination] << endl;
  cout << ansWay.size() + 1 << endl;
  cout << origin << " ";
  for (auto w : ansWay) {
    cout << w << " ";
  }

  return 0;
}
