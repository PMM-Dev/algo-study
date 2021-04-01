// 2468 안정역역
// Memory : 2152 KB
// Time : 32 ms
#include <iostream>
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

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> area(n, vector<int>(n));
  For(i, 0, n) {
    For(j, 0, n) { cin >> area[i][j]; }
  }

  int maxCnt = 1;
  for (int i = 1; i <= 100; i++) {
    vector<vector<bool>> flood(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (area[j][k] <= i)
          flood[j][k] = true;
      }
    }

    int tmpCnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (flood[j][k] || visited[j][k])
          continue;

        tmpCnt++;
        queue<pair<int, int>> q;
        q.push({j, k});
        visited[j][k] = true;
        while (!q.empty()) {
          auto np = q.front();
          q.pop();

          for (int t = 0; t < 4; t++) {
            int nr = np.F + dr[t];
            int nc = np.S + dc[t];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || flood[nr][nc] ||
                visited[nr][nc])
              continue;

            q.push({nr, nc});
            visited[nr][nc] = true;
          }
        }
      }
    }
    maxCnt = max(maxCnt, tmpCnt);
    if (tmpCnt == 0)
      break;
  }

  cout << maxCnt;
  return 0;
}
