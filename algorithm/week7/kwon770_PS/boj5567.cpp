// Memory : 2152 KB
// Time : 0 ms
#include <iostream>
#include <set>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<short>> friendship(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    friendship[a].push_back(b);
    friendship[b].push_back(a);
  }

  set<short> attendee;
  for (auto dfriend : friendship[1]) {
    attendee.insert(dfriend);
    for (auto ffriend : friendship[dfriend]) {
      if (ffriend != 1) {
        attendee.insert(ffriend);
      }
    }
  }

  cout << attendee.size();
  return 0;
}
