// MeMory : 2912 KB
// Time : 24 ms
#include <iostream>
#include <queue>
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

  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  For(i, 0, n) {
    int inp;
    cin >> inp;
    pq.push(inp);
  }

  long long ans = 0;
  while (!pq.empty() && pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    long long sum = a + b;
    ans += sum;

    if (!pq.empty())
      pq.push(sum);
  }
  cout << ans;

  return 0;
}
