// Memoty : 2272 KB
// Time : 120 ms
#include <cmath>
#include <iostream>
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

int n, l, r;
bool movable = true;
int totalPopulation;

vector<vector<int>> populations;
vector<pair<int, int>> unions;

int returnIdx(int r, int c) { return r * n + c; }

void dfs(vector<vector<bool>> &visited, int row, int col) {
  totalPopulation += populations[row][col];

  for (int i = 0; i < 4; i++) {
    int nRow = row + dr[i];
    int nCol = col + dc[i];
    if (nRow < 0 || nCol < 0 || n <= nRow || n <= nCol || visited[nRow][nCol])
      continue;

    int populationGap = abs(populations[row][col] - populations[nRow][nCol]);
    if (populationGap < l || populationGap > r)
      continue;

    movable = true;
    unions.push_back({nRow, nCol});
    visited[nRow][nCol] = true;
    dfs(visited, nRow, nCol);
  }
}

void openBorder() {
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j])
        continue;

      totalPopulation = 0;
      unions.push_back({i, j});
      visited[i][j] = true;
      dfs(visited, i, j);

      int averagePopulation = totalPopulation / sz(unions);
      while (!unions.empty()) {
        pair<int, int> unionCoord = unions.back();
        unions.pop_back();
        populations[unionCoord.F][unionCoord.S] = averagePopulation;
      }
      unions.clear();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l >> r;

  populations.resize(n, vector<int>(n));
  For(i, 0, n) {
    For(j, 0, n) { cin >> populations[i][j]; }
  }

  int cnt = 0;
  while (movable) {
    movable = false;
    openBorder();
    if (movable)
      cnt++;
  }
  cout << cnt;

  return 0;
}
