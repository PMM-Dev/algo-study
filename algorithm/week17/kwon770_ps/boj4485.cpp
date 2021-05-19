// Memory : 2268 KB
// Time : 4 ms
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

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class Pos {
public:
  int cost;
  int row;
  int col;
  bool operator()(Pos a, Pos b) { return a.cost > b.cost; }
};

int solve(int n, const vector<vector<int>> &cave) {
  vector<vector<int>> lose(n, vector<int>(n, INT_MAX));
  priority_queue<Pos> pq;
  pq.push(Pos{cave[0][0], 0, 0});
  lose[0][0] = cave[0][0];

  while (!pq.empty()) {
    int cost = pq.top().cost;
    int row = pq.top().row;
    int col = pq.top().col;
    pq.pop();

    if (lose[row][col] < cost)
      continue;

    for (int i = 0; i < 4; i++) {
      int nRow = row + dr[i];
      int nCol = col + dc[i];
      if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= n)
        continue;

      int nCost = cost + cave[nRow][nCol];
      if (lose[nRow][nCol] <= nCost)
        continue;

      lose[nRow][nCol] = nCost;
      pq.push(Pos{nCost, nRow, nCol});
    }
  }

  return lose[n - 1][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int idx = 1, n;
  while (true) {
    cin >> n;
    if (n == 0)
      break;

    vector<vector<int>> cave(n, vector<int>(n));
    For(i, 0, n) {
      For(j, 0, n) { cin >> cave[i][j]; }
    }

    cout << "Problem " << idx << ": " << solve(n, cave) << endl;
    idx++;
  }

  return 0;
}
