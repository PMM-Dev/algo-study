// WA
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

#define For(i, j, k) for (int i = j; i < (int)(k); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<priority_queue<int>> pqs(n, priority_queue<int>());
  For(i, 0, n) {
    For(j, 0, n) {
      int ipt;
      cin >> ipt;
      pqs[j].push(ipt);
    }
  }

  int cnt = n, maxIdx, ans;
  while (cnt--) {
    int maxVal = INT_MIN;
    For(i, 0, n) {
      if (pqs[i].top() > maxVal) {
        maxIdx = i;
        maxVal = pqs[i].top();
      }
    }

    pqs[maxIdx].pop();
    ans = maxVal;
  }
  cout << ans;

  return 0;
}
