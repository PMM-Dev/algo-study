// Memory : 6248 KB
// Time : 52 ms
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

struct {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return a.first > b.first;
  }
} Cmp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x, y, m, inp;
  cin >> x >> y >> m;
  vector<pair<int, int>> damage;
  vector<pair<int, int>> item;
  for (int i = 1; i <= x; i++) {
    cin >> inp;
    damage.push_back(make_pair(inp, i));
  }
  sort(damage.begin(), damage.end(), Cmp);
  for (int i = 1; i <= y; i++) {
    cin >> inp;
    item.push_back(make_pair(inp, i));
  }
  sort(item.begin(), item.end(), Cmp);

  vector<int> order;
  int health = m;
  auto itemIter = item.begin();
  for (auto damageIter = damage.begin(); damageIter != damage.end();
       damageIter++) {
    health -= (*damageIter).first;
    if (health <= 0) {
      cout << 0;
      return 0;
    }

    order.push_back(-1 * (*damageIter).second);
    while (itemIter != item.end() && m - health >= (*itemIter).first) {
      health += (*itemIter).first;
      order.push_back((*itemIter).second);
      itemIter++;
    }
  }

  while (itemIter != item.end()) {
    order.push_back((*itemIter).second);
    itemIter++;
  }

  for (int o : order)
    cout << o << endl;
  return 0;
}
