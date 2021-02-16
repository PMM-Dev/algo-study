// Memory : 2148 KB
// Time : 0 ms
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

#define F first
#define S second

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int maxRow = -1, maxCol = -1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<bool>> grid(101, vector<bool>(101, false));
  while (n--) {
    int r, c, d, g;
    cin >> c >> r >> d >> g;
    vector<pair<int, int>> dots;
    dots.push_back({r, c});

    for (int i = 0; i <= g; i++) {
      if (dots.size() == 1) {
        dots.push_back({dots[0].F + dr[d], dots[0].S + dc[d]});
      } else {
        pair<int, int> standard = dots.back();
        for (auto iter = dots.rbegin() + 1; iter < dots.rend(); iter++) {
          int row = standard.F - (*iter).F;
          int col = standard.S - (*iter).S;
          dots.push_back({standard.F + (-1 * col), standard.S + row});
        }
      }
    }

    for (auto dot : dots) {
      grid[dot.F][dot.S] = true;
      maxRow = max(maxRow, dot.F);
      maxCol = max(maxCol, dot.S);
    }
  }

  int ans = 0;
  for (int r = 0; r < maxRow; r++) {
    for (int c = 0; c < maxCol; c++) {
      int tmpRow[] = {r, r + 1, r + 1, r};
      int tmpCol[] = {c, c, c + 1, c + 1};
      bool success = true;
      for (int i = 0; i < 4; i++) {
        if (!grid[tmpRow[i]][tmpCol[i]]) {
          success = false;
          break;
        }
      }

      if (success)
        ans++;
    }
  }

  cout << ans;
  return 0;
}
