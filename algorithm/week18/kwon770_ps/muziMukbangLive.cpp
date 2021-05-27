#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int solution(vector<int> food_times, long long k) {
  int size = sz(food_times);
  vector<int> sizes(food_times);
  sort(sizes.begin(), sizes.end());

  auto sizeIter = sizes.begin();

  long long ateCnt = 0;
  bool isRound = false;
  while (k != 0 && k >= size) {
    isRound = true;

    int cur = *sizeIter;
    k -= size;

    while (sizeIter != sizes.end() && *sizeIter == cur) {
      sizeIter++;
      ateCnt++;
    }

    if (sizeIter == sizes.end())
      return -1;

    size -= ateCnt;
    ateCnt = 0;
  }

  int ateSize;
  if (isRound)
    ateSize = *(sizeIter - 1);
  else
    ateSize = -1;
  if (k == 0) {
    for (auto iter = food_times.begin(); iter != food_times.end(); iter++) {
      if (*iter <= ateSize)
        continue;

      return (iter - food_times.begin()) + 1;
    }

    return -1;
  } else {
    for (auto iter = food_times.begin(); iter != food_times.end(); iter++) {
      if (*iter <= ateSize)
        continue;
      if (k == 0)
        return (iter - food_times.begin()) + 1;

      k--;
    }

    return -1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout << solution({4, 2, 3, 6, 7, 1, 5, 8}, 16);

  return 0;
}
