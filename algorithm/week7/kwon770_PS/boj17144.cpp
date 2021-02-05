// Memory : 2152 KB
// Time : 40 ms
#include <iostream>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> dr = {0, -1, 0, 1};
vector<int> dc = {1, 0, -1, 0};

int r, c, t;
vector<vector<int>> room;
vector<vector<int>> tmpRoom;
pair<int, int> topPurifier = make_pair(-1, -1);
pair<int, int> bottomPurifier;

void spreadDust() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (room[i][j] == 0 || room[i][j] == -1)
        continue;

      int spreadedDust = room[i][j] / 5;
      int spreadedCnt = 0;
      for (int k = 0; k < 4; k++) {
        int tr = i + dr[k];
        int tc = j + dc[k];
        if (tr < 0 || tc < 0 || tr >= r || tc >= c || room[tr][tc] == -1)
          continue;

        tmpRoom[tr][tc] += spreadedDust;
        spreadedCnt++;
      }
      tmpRoom[i][j] -= spreadedDust * spreadedCnt;
    }
  }
  room = tmpRoom;
}

void circulateAir(int fr, int fc, int dustAmount, bool clockwise, int dir) {
  int tr = fr + dr[dir];
  int tc = fc + dc[dir];
  if (tr < 0 || tc < 0 || tr >= r || tc >= c) {
    if (clockwise)
      dir--;
    else
      dir++;

    if (dir > 3)
      dir = 0;
    else if (dir < 0)
      dir = 3;

    tr = fr + dr[dir];
    tc = fc + dc[dir];
  }
  if (room[tr][tc] == -1)
    return;

  int tmpDustAmount = room[tr][tc];
  room[tr][tc] = dustAmount;
  circulateAir(tr, tc, tmpDustAmount, clockwise, dir);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c >> t;
  room.resize(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> room[i][j];

      if (room[i][j] == -1) {
        if (topPurifier.first == -1) {
          topPurifier = make_pair(i, j);
        } else {
          bottomPurifier = make_pair(i, j);
        }
      }
    }
  }

  while (t--) {
    tmpRoom = room;
    spreadDust();
    circulateAir(topPurifier.first, topPurifier.second, 0, false, 0);
    circulateAir(bottomPurifier.first, bottomPurifier.second, 0, true, 0);
  }

  int ans = 0;
  for (auto r : room) {
    for (auto c : r) {
      if (c != -1)
        ans += c;
    }
  }
  cout << ans;
  return 0;
}
