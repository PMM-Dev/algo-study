// 11403 경로 찾기
// Memory : 2148 KB
// Time : 0 ms
#include <iostream>
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
  int n;
  vector<int> edges;

  Node(int n) : n(n) {}
};

vector<Node> nodes;

void drawEdge(bool first, int curNode, vector<int> &e, vector<bool> &visited) {
  if (visited[curNode])
    return;

  if (!first) {
    visited[curNode] = true;
    e[curNode] = 1;
  }
  for (auto edge : nodes[curNode].edges) {
    drawEdge(false, edge, e, visited);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  For(i, 0, n) {
    nodes.push_back(Node(i));

    For(j, 0, n) {
      int e;
      cin >> e;

      if (e == 1)
        nodes.back().edges.push_back(j);
    }
  }

  For(i, 0, n) {
    vector<int> e(n, 0);
    vector<bool> visited(n, false);
    drawEdge(true, i, e, visited);

    for (auto ee : e) {
      cout << ee << " ";
    }
    cout << endl;
  }

  return 0;
}
