// Memory : 0 KB
// Time : 46 ms
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, n;
  vector<int> ball;
  cin >> t;
  while (t--) {
    cin >> n;

    int idx = n, cnt = 0, maxCnt = 0, prevBall, ball;
    while (idx--) {
      cin >> ball;
      if (idx + 1 == n)
        prevBall = ball;

      if (prevBall == ball) {
        cnt++;
      } else {
        cnt = 1;
      }
      maxCnt = max(cnt, maxCnt);

      prevBall = ball;
    }

    cout << maxCnt << endl;
  }

  return 0;
}
