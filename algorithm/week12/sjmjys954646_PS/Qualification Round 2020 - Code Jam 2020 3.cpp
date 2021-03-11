//freopen("input.txt", "r", stdin);
//6636kb 48ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.S.F == b.S.F)
    {
        return a.S.S < a.S.S;
    }
    else
    {
        return a.S.F < b.S.F;
    }
}

bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.F < b.F;
}

void solve()
{
    int N;

    vector<pair<int, pair<int, int>>> W;
    vector<pair<int, pair<int, int>>> C;
    vector<pair<int, pair<int, int>>> J;
    bool check = true;

    cin >> N;

    W.resize(N);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        W[i] = make_pair(i, make_pair(x, y));
    }

    sort(W.begin(), W.end(), compare);

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            C.push_back(W[i]);
            continue;
        }

        if (C.back().S.S <= W[i].S.F || W[i].S.S <= C.back().S.F)
        {
            C.push_back(W[i]);
        }
        else
        {
            if (J.size() == 0 || J.back().S.S <= W[i].S.F || W[i].S.S <= J.back().S.F)
            {
                J.push_back(W[i]);
            }
            else
            {
                check = false;
                break;
            }
        }
    }
    sort(C.begin(), C.end(), compare2);
    sort(J.begin(), J.end(), compare2);

    if (check)
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < W.size(); i++)
        {
            if (a == C.size())
            {
                while (i < W.size())
                {
                    cout << "J";
                    i++;
                }
                break;
            }
            else if (b == J.size())
            {
                while (i < W.size())
                {
                    cout << "C";
                    i++;
                }
                break;
            }

            if (C[a].F == i)
            {
                cout << "C";
                a++;
            }
            else if (J[b].F == i)
            {
                cout << "J";
                b++;
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE"
             << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;
    int i = 1;

    while (T--)
    {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }

    return 0;
}