// 그리디 + 백터를 이용하여 인덱스별로 정답을 저장하는 백트래킹 방식을 이용하여
// 풀었음
#include <algorithm>
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

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  if (a.S.F != b.S.F)
    return a.S.F < b.S.F;
  else
    return a.S.S < b.S.S;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  vector<pair<int, pair<int, int>>> schedule;
  rep(i, t) {
    int n;
    cin >> n;

    schedule.clear();
    rep(j, n) {
      int s, e;
      cin >> s >> e;
      schedule.push_back({j, {s, e}});
    }
    sort(schedule.begin(), schedule.end(), cmp);

    vector<char> ans(n);
    int c = -1, j = -1;
    for (auto s : schedule) {
      int cTime = s.S.F - c;
      int jTime = s.S.F - j;
      if (cTime < 0 && jTime < 0) {
        ans[0] = 'I';
        break;
      } else if (cTime > jTime) {
        ans[s.F] = 'C';
        c = s.S.S;
      } else {
        ans[s.F] = 'J';
        j = s.S.S;
      }
    }

    cout << "Case #" << i + 1 << ": ";
    if (ans[0] == 'I')
      cout << "IMPOSSIBLE";
    else {
      for (auto a : ans) {
        cout << a;
      }
    }
    cout << endl;
  }

  return 0;
}
