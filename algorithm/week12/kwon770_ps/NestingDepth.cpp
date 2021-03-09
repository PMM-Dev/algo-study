#include <iostream>
#include <list>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  list<char> s;
  int t;
  cin >> t;
  rep(i, t) {
    s.clear();
    string str;
    cin >> str;
    for (auto st : str)
      s.push_back(st);

    int depth = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
      int iterInt = *iter - '0';
      while (depth < iterInt) {
        s.insert(iter, '(');
        depth++;
      }
      while (depth > iterInt) {
        s.insert(iter, ')');
        depth--;
      }
    }

    while (depth > 0) {
      s.insert(s.end(), ')');
      depth--;
    }

    cout << "Case #" << i + 1 << ": ";
    for (auto iter = s.begin(); iter != s.end(); iter++) {
      cout << *iter;
    }
    cout << endl;
  }

  return 0;
}
