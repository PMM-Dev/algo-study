// 5427 불
// Memory : 5427 KB
// Time : 80 ms
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

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int c, r;

vector<pair<int, int>> fires;
void spreadFire(const vector<vector<char>> &building,
                vector<vector<bool>> &danger) {

  vector<pair<int, int>> newFires;
  for (auto fire : fires) {
    for (int d = 0; d < 4; d++) {
      int nr = fire.F + dr[d];
      int nc = fire.S + dc[d];
      if (nr < 0 || nr >= r || nc < 0 || nc >= c || building[nr][nc] != '.' ||
          danger[nr][nc])
        continue;

      danger[nr][nc] = true;
      newFires.push_back({nr, nc});
    }
  }

  fires = newFires;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  For(i, 0, t) {
    cin >> c >> r;
    vector<vector<char>> building(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<vector<bool>> danger(r, vector<bool>(c, false));
    fires.clear();
    pair<int, int> start;
    For(j, 0, r) {
      For(k, 0, c) {
        cin >> building[j][k];
        if (building[j][k] == '@') {
          start = {j, k};
          building[j][k] = '.';
        }
        if (building[j][k] == '*') {
          fires.push_back({j, k});
          danger[j][k] = true;
        }
      }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {start.F, start.S}});
    visited[start.F][start.S] = true;
    int ans = 0, time = -1;
    bool exit = false;

    while (!q.empty()) {
      auto pos = q.front();
      q.pop();
      if (time != pos.F) {
        time = pos.F;
        spreadFire(building, danger);
      }

      for (int d = 0; d < 4; d++) {
        int nr = pos.S.F + dr[d];
        int nc = pos.S.S + dc[d];

        if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
          exit = true;
          ans = pos.F + 1;
          break;
        }

        if (visited[nr][nc] || building[nr][nc] != '.' || danger[nr][nc])
          continue;

        q.push({pos.F + 1, {nr, nc}});
        visited[nr][nc] = true;
      }

      if (exit)
        break;
    }

    if (exit)
      cout << ans << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
