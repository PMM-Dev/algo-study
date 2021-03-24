// Memory : 6312 KB
// Time : 40 ms
#include <climits>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<pair<char, string>> birds(n);
  vector<int> disturb(m, 0);
  int minDisturb = INT_MAX;
  int killIdx;
  For(i, 0, n) {
    cin >> birds[i].F;
    cin >> birds[i].S;

    for (int j = 0; j < m; j++)
      if (birds[i].F == 'L')
        disturb[j] -= birds[i].S[j] - '0';
      else
        disturb[j] += birds[i].S[j] - '0';
  }

  int idx = 0;
  for (auto bird : birds) {
    idx++;

    int curDisturb = 0, curMaxDisturb = -1;
    for (int i = 0; i < m; i++) {
      if (bird.F == 'L')
        curDisturb += disturb[i] + (bird.S[i] - '0');
      else
        curDisturb += disturb[i] - (bird.S[i] - '0');

      curMaxDisturb = max(curMaxDisturb, abs(curDisturb));
    }

    if (curMaxDisturb < minDisturb) {
      minDisturb = curMaxDisturb;
      killIdx = idx;
    }
  }

  cout << killIdx << endl << minDisturb;
  return 0;
}
