// Memory : 2016 KB
// Time : 0 ms
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

vector<char> chars;
int l, c;

void recursion(int cnt, int idx, vector<char> &passwd) {
  passwd.push_back(chars[idx]);
  cnt++;

  if (cnt == l) {
    int aeiou = 0, notAeiou = 0;
    for (auto p : passwd) {
      if (p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u')
        aeiou++;
      else
        notAeiou++;
    }
    if (aeiou < 1 || notAeiou < 2)
      return;

    for (auto p : passwd)
      cout << p;
    cout << endl;
    return;
  } else {
    for (int i = idx + 1; i < c; i++) {
      recursion(cnt, i, passwd);
      passwd.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> l >> c;
  For(i, 0, c) {
    char ipt;
    cin >> ipt;
    chars.push_back(ipt);
  }
  sort(chars.begin(), chars.end());

  vector<char> passwd;
  for (int i = 0; i < c - l + 1; i++) {
    passwd.clear();
    recursion(0, i, passwd);
  }

  return 0;
}
