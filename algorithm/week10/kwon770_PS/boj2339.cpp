// Memory : 2020 KN
// Time : 16 ms
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int n, ans = 0;
vector<vector<int>> rock;

pair<int, bool> checkValue(int fromR, int toR, int fromC, int toC) {
  int value = 0;
  bool clean = true;
  for (int i = fromR; i <= toR; i++) {
    for (int j = fromC; j <= toC; j++) {
      if (rock[i][j] == 1)
        clean = false;

      if (rock[i][j] == 2) {
        value++;
      };
    }
  }
  return {value, clean};
}

int recursion(int fromR, int toR, int fromC, int toC, bool dir) {
  pair<int, bool> cur = checkValue(fromR, toR, fromC, toC);
  if (cur.F == 1 && cur.S == true)
    return 1;

  int cnt = 0;
  if (dir) {
    for (int i = fromR + 1; i <= toR - 1; i++) {
      bool cutable = true;
      for (int j = fromC; j <= toC; j++) {
        if (rock[i][j] == 2) {
          cutable = false;
          break;
        }
      }
      if (!cutable)
        continue;

      pair<int, bool> top = checkValue(fromR, i - 1, fromC, toC);
      pair<int, bool> bottom = checkValue(i + 1, toR, fromC, toC);

      if (top.F == 0 || bottom.F == 0 || (top.F == 1 && top.S == false) ||
          (bottom.F == 1 && bottom.S == false))
        continue;
      else if (top.F == 1 && bottom.F == 1 && top.S == true &&
               bottom.S == true) {
        cnt++;
        continue;
      } else {
        cnt += recursion(fromR, i - 1, fromC, toC, !dir) *
               recursion(i + 1, toR, fromC, toC, !dir);
      }
    }
  } else {
    for (int j = fromC + 1; j <= toC - 1; j++) {
      bool cutable = true;
      for (int i = fromR; i <= toR; i++) {
        if (rock[i][j] == 2) {
          cutable = false;
          break;
        }
      }
      if (!cutable)
        continue;

      pair<int, bool> left = checkValue(fromR, toR, fromC, j - 1);
      pair<int, bool> right = checkValue(fromR, toR, j + 1, toC);

      if (left.F == 0 || right.F == 0 || (left.F == 1 && left.S == false) ||
          (right.F == 1 && right.S == false))
        continue;
      else if (left.F == 1 && right.F == 1 && left.S == true &&
               right.S == true) {
        cnt++;
        continue;
      } else {
        cnt += recursion(fromR, toR, fromC, j - 1, !dir) *
               recursion(fromR, toR, j + 1, toC, !dir);
      }
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  rock.resize(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) { cin >> rock[i][j]; }
  }

  int ans = recursion(0, n - 1, 0, n - 1, true) +
            recursion(0, n - 1, 0, n - 1, false);
  if (ans == 0)
    cout << -1;
  else
    cout << ans;
  return 0;
}
