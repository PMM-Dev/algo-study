//20116kb 388ms
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

priority_queue<pii, vector<pii>> pq;
multiset<int> backpack;
int N, K;
ll ans = 0;

int main()
{
    scanf("%d %d", &N, &K);

    rep(i, N)
    {
        int M, V;
        scanf("%d %d", &M, &V);
        pq.push({V, M}); //가치  무게
    }

    rep(i, K)
    {
        int T;
        scanf("%d", &T);
        backpack.insert(T);
    }

    while (!pq.empty())
    {
        int curM = pq.top().S;
        int curV = pq.top().F;

        pq.pop();

        multiset<int>::iterator it = backpack.lower_bound(curM);

        if (it == backpack.end())
            continue;

        ans += curV;
        backpack.erase(it);
    }

    printf("%lld", ans);

    return 0;
}
