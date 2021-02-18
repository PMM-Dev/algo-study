// Memory : 6084 KB
// Time : 104 ms
#include <deque>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;

class Fireball {
public:
  int r;
  int c;
  int m;
  int s;
  int d;

  Fireball(int _r, int _c, int _m, int _s, int _d) {
    r = _r;
    c = _c;
    m = _m;
    s = _s;
    d = _d;
  }

  void move() {
    r += dr[d] * s;
    c += dc[d] * s;
    r %= n;
    c %= n;
    if (r < 1)
      r += n;
    if (c < 1)
      c += n;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  vector<vector<deque<Fireball>>> arr(
      n + 1, vector<deque<Fireball>>(n + 1, deque<Fireball>()));
  vector<vector<deque<Fireball>>> tmpArr(
      n + 1, vector<deque<Fireball>>(n + 1, deque<Fireball>()));
  while (m--) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    arr[r][c].push_back(Fireball(r, c, m, s, d));
  }

  while (k--) {
    // move
    for (auto &row : arr) {
      for (auto &col : row) {
        for (auto fireball : col) {
          fireball.move();
          tmpArr[fireball.r][fireball.c].push_back(fireball);
          col.pop_front();
        }
      }
    }
    arr = tmpArr;
    for (auto &row : tmpArr)
      for (auto &col : row)
        col.clear();

    // calculate
    for (auto &row : arr) {
      for (auto &col : row) {
        int cnt = 0;
        int mSum = 0;
        int sSum = 0;
        bool sameDir = true;
        int initDir = -1;
        int curR, curC;
        for (auto fireball : col) {
          if (initDir == -1) {
            initDir = fireball.d % 2;
            curR = fireball.r;
            curC = fireball.c;
          } else if (initDir != fireball.d % 2)
            sameDir = false;

          mSum += fireball.m;
          sSum += fireball.s;

          cnt++;
        }

        if (cnt > 1) {
          mSum /= 5;
          sSum /= cnt;
          col.clear();
          if (mSum == 0)
            continue;

          int tmpDir = sameDir ? 0 : 1;
          for (int i = 0; i < 4; i++) {
            col.push_back(Fireball(curR, curC, mSum, sSum, tmpDir));
            tmpDir += 2;
          }
        }
      }
    }
  }

  int ans = 0;
  for (auto row : arr) {
    for (auto col : row) {
      for (auto fireball : col) {
        ans += fireball.m;
      }
    }
  }
  cout << ans;

  return 0;
}
