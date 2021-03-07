#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  rep(i, t) {
    int n;
    cin >> n;
    vector<vector<int>> colCnt(n, vector<int>(n + 1, 0));

    int k = 0, r = 0, c = 0;
    rep(j, n) {
      vector<int> rowCnt(n + 1, 0);
      rep(p, n) {
        int inp;
        cin >> inp;

        if (j == p)
          k += inp;

        rowCnt[inp]++;
        colCnt[p][inp]++;
      }

      for (auto num : rowCnt) {
        if (num > 1) {
          r++;
          break;
        }
      }
    }

    for (auto col : colCnt) {
      for (auto num : col) {
        if (num > 1) {
          c++;
          break;
        }
      }
    }

    if (r == 1)
      r = 0;
    if (c == 1)
      c = 0;
    cout << "Case #" << i + 1 << ": " << k << " " << r << " " << c << endl;
  }

  return 0;
}
