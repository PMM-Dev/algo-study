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

ll N, H;
vector<pair<ll, pair<ll, ll>>> q;

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &N, &H);

    rep(i, N)
    {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        q.pb({a, {b, c}});
    }

    ll curHP = 0;
    ll ans = LLONG_MAX - 1;

    rep(i, N)
    {
        if (q[i].F == 1)
        {
            if (q[i].S.S % H == 0)
            {
                curHP -= q[i].S.F * (q[i].S.S / H - 1);
            }
            else
            {
                curHP -= q[i].S.F * (q[i].S.S / H);
            }
        }
        else
        {
            H += q[i].S.F;
            if (curHP + q[i].S.S >= 0)
                curHP = 0;
            else
                curHP += q[i].S.S;
        }
        ans = min(curHP, ans);
    }

    cout << -ans + 1;

    return 0;
}