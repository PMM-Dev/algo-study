// Memory : 2020 KB
// Time : 0 ms
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

vector<bool> monkey;
int n, cnt = 0;

void print() {
    for (int i = 1; i <= n; i++) {
        if (monkey[i])
            cout << "A";
        else
            cout << "B";
    }
    cout << endl;
}

void solve() {
    int from = 1, to = n, mid;
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {from, to}});
    int prevDepth = 0;
    while (!q.empty()) {
        int depth = q.front().F;
        if (prevDepth != depth) {
            print();
            cnt++;
            prevDepth = depth;
        }

        from = q.front().S.F;
        to = q.front().S.S;
        mid = from + ((to - from) / 2);
        for (int i = from; i <= mid; i++) {
            monkey[i] = true;
        }
        for (int i = mid + 1; i <= to; i++) {
            monkey[i] = false;
        }

        if (from < mid)
            q.push({depth + 1, {from, mid}});
        if (mid + 1 < to)
            q.push({depth + 1, {mid + 1, to}});
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    monkey.resize(n + 1);

    solve();
    for (int i = ++cnt; i <= 7; i++) {
        print();
    }

    return 0;
}
