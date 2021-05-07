// 14499 주사위굴리기
// Memory : 2020 KB
// Time : 0ms
#include <deque>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

#define TOP_IDX 0
#define BOTTOM_IDX 2
int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};
int N, M, x, y, K;

vector<vector<int>> imap;
deque<int> diceHor(4, 0);
deque<int> diceVer(4, 0);

void rotateDice(int cmd) {
  if (cmd == 1 || cmd == 2) {
    if (cmd == 1) {
      int move = diceHor.back();
      diceHor.pop_back();
      diceHor.push_front(move);
    } else {
      int move = diceHor.front();
      diceHor.pop_front();
      diceHor.push_back(move);
    }

    diceVer[TOP_IDX] = diceHor[TOP_IDX];
    diceVer[BOTTOM_IDX] = diceHor[BOTTOM_IDX];
  } else if (cmd == 3 || cmd == 4) {
    if (cmd == 3) {
      int move = diceVer.front();
      diceVer.pop_front();
      diceVer.push_back(move);
    } else {
      int move = diceVer.back();
      diceVer.pop_back();
      diceVer.push_front(move);
    }

    diceHor[TOP_IDX] = diceVer[TOP_IDX];
    diceHor[BOTTOM_IDX] = diceVer[BOTTOM_IDX];
  }
}

void roll(int cmd) {
  int nr = x + dr[cmd];
  int nc = y + dc[cmd];
  if (nr < 0 || nc < 0 || nr >= N || nc >= M)
    return;

  rotateDice(cmd);
  if (imap[nr][nc] == 0) {
    imap[nr][nc] = diceHor[BOTTOM_IDX];
  } else {
    diceHor[BOTTOM_IDX] = imap[nr][nc];
    diceVer[BOTTOM_IDX] = imap[nr][nc];
    imap[nr][nc] = 0;
  }

  cout << diceHor[TOP_IDX] << endl;

  x = nr;
  y = nc;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M >> x >> y >> K;
  imap.resize(N, vector<int>(M));
  For(i, 0, N) {
    For(j, 0, M) { cin >> imap[i][j]; }
  }

  For(i, 0, K) {
    int cmd;
    cin >> cmd;
    roll(cmd);
  }

  return 0;
}
