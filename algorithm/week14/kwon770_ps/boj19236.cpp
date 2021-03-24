#include <algorithm>
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

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<vector<int>> water(4, vector<int>(4));
vector<pair<int, pair<int, int>>> fish(17);
pair<int, pair<int, int>> shark;
int maxFish = -1;

bool availableForFish(int r, int c) {
  if (r < 0 || r >= 4 || c < 0 || c >= 4 || water[r][c] == -1)
    return false;
  else
    return true;
}

void fishMove() {
  int idx = -1;
  for (auto f : fish) {
    idx++;
    if (idx == 0)
      continue;
    if (f.F == -1)
      continue;

    int newFishR, newFishC, newDir = f.F;
    bool cantMove = false;
    do {
      newFishR = f.S.F + dr[newDir];
      newFishC = f.S.S + dc[newDir];
      if (availableForFish(newFishR, newFishC))
        break;

      newDir += 1;
      if (newDir == 8)
        newDir = 0;
      if (f.F == newDir) {
        cantMove = true;
        break;
      }
    } while (true);

    if (!cantMove)
      swap(water[f.S.F][f.S.S], water[newFishR][newFishC]);

    cout << idx << endl;
    for (auto a : water) {
      for (auto b : a)
        cout << b << " ";
      cout << endl;
    }
    cout << endl;
  }
}

void simulate(int curFish) {
  fishMove();

  vector<int> sharkMove;
  int sharkR = shark.S.F, sharkC = shark.S.S, move = 1;
  while (sharkR >= 0 && sharkR < 4 && sharkC >= 0 && sharkC < 4) {
    if (water[sharkR][sharkC] > 0)
      sharkMove.push_back(move);

    sharkR += dr[shark.F];
    sharkC += dc[shark.F];
    move++;
  }

  for (auto s : sharkMove)
    cout << s;
  cout << endl;

  if (sharkMove.empty()) {
    maxFish = max(curFish, maxFish);
    return;
  }

  for (auto move : sharkMove) {
    auto originShark = shark;
    int newSharkR = shark.S.F + (move * shark.F);
    int newSharkC = shark.S.S + (move * shark.F);
    auto originFish = fish[water[newSharkR][newSharkC]];
    int originFishNum = water[newSharkR][newSharkC];

    water[shark.S.F][shark.S.S] = 0;
    water[newSharkR][newSharkC] = -1;
    shark = originFish;
    fish[originFishNum] = {-1, {-1, -1}};
    simulate(curFish + originFishNum);
    shark = originShark;
    fish[originFishNum] = originFish;
    water[shark.S.F][shark.S.S] = -1;
    water[newSharkR][newSharkC] = originFishNum;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  For(i, 0, 4) {
    For(j, 0, 4) {
      int a, b;
      cin >> a >> b;
      water[i][j] = a;
      fish[a] = {b - 1, {i, j}};
    }
  }

  shark = fish[water[0][0]];
  fish[water[0][0]] = {-1, {-1, -1}};
  water[0][0] = -1;
  simulate(0);

  cout << maxFish;
  return 0;
}
