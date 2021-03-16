// WA
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

  vector<int> val;
  priority_queue<int> pq;

  int t;
  cin >> t;
  For(i, 0, t) {
    int m;
    cin >> m;

    int valIdx = 1;
    val.clear();
    For(j, 0, m) {
      int ipt;
      cin >> ipt;
      pq.push(ipt);
      val.push_back(pq.top());

      if (j % 2 != 0) {
      }
    }

    return 0;
  }
