// Memory : 2152 KB
// Time : 16 ms
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int dR[] = {-1, 0, 1, 0};
int dC[] = {0, 1, 0, -1};

int n, ans = 0;

void move(vector<vector<int>> &curArr, vector<vector<int>> &tmpArr,
          vector<vector<bool>> &combined, int d, int i, int j) {
  if (curArr[i][j] == 0)
    return;

  int row = i, col = j;
  while (tmpArr[row][col] == 0) {
    row += dR[d];
    col += dC[d];
    if (row < 0 || row > n - 1 || col < 0 || col > n - 1) {
      row -= dR[d];
      col -= dC[d];
      break;
    }
  }

  if ((tmpArr[row][col] != 0 && tmpArr[row][col] != curArr[i][j]) ||
      (tmpArr[row][col] == curArr[i][j] && combined[row][col])) {
    row -= dR[d];
    col -= dC[d];
  }

  if (tmpArr[row][col]) {
    tmpArr[row][col] *= 2;
    combined[row][col] = true;
  } else {
    tmpArr[row][col] = curArr[i][j];
  }
}

void simulate(vector<vector<int>> curArr, int cnt) {
  if (cnt == 5) {
    for (auto row : curArr) {
      for (auto col : row) {
        ans = max(ans, col);
      }
    }
    return;
  }

  for (int d = 0; d < 4; d++) {
    vector<vector<int>> tmpArr(n, vector<int>(n, 0));
    vector<vector<bool>> combined(n, vector<bool>(n, false));

    if (d == 0) {
      for (int j = 0; j <= n - 1; j++)
        for (int i = 0; i <= n - 1; i++)
          move(curArr, tmpArr, combined, d, i, j);
    } else if (d == 1) {
      for (int i = 0; i <= n - 1; i++)
        for (int j = n - 1; j >= 0; j--)
          move(curArr, tmpArr, combined, d, i, j);
    } else if (d == 2) {
      for (int j = 0; j <= n - 1; j++)
        for (int i = n - 1; i >= 0; i--)
          move(curArr, tmpArr, combined, d, i, j);
    } else if (d == 3) {
      for (int i = 0; i <= n - 1; i++)
        for (int j = 0; j <= n - 1; j++)
          move(curArr, tmpArr, combined, d, i, j);
    }

    simulate(tmpArr, cnt + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  simulate(arr, 0);
  cout << ans;

  return 0;
}
