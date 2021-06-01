// Memory : 2156 KB
// Time : 0 ms
#include <cmath>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int n, l;
vector<vector<int>> maps;

bool solve(int idx, bool rowDir) {
  int prevHeight, sameHeightCount = 1;
  bool downDir = false;
  if (rowDir)
    prevHeight = maps[0][idx];
  else
    prevHeight = maps[idx][0];

  for (int i = 1; i < n; i++) {
    int row, col;
    if (rowDir) {
      row = i;
      col = idx;
    } else {
      row = idx;
      col = i;
    }

    if (prevHeight != maps[row][col]) {
      if (abs(prevHeight - maps[row][col]) > 1)
        return false;
      if (downDir)
        return false;

      if (prevHeight < maps[row][col]) {
        if (sameHeightCount < l)
          return false;

        sameHeightCount = 1;
      } else {
        downDir = true;
        sameHeightCount = 1;
      }
    } else {
      sameHeightCount++;
    }

    if (downDir && sameHeightCount == l) {
      downDir = false;
      sameHeightCount = 0;
    }

    prevHeight = maps[row][col];
  }

  if (downDir)
    return false;
  else
    return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l;
  maps.resize(n, vector<int>(n));
  For(i, 0, n) {
    For(j, 0, n) { cin >> maps[i][j]; }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (solve(i, true))
      ans++;

    if (solve(i, false))
      ans++;
  }

  cout << ans;
  return 0;
}
