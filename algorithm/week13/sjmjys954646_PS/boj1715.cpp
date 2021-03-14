//freopen("input.txt", "r", stdin);
//2796kb 28ms
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

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{

    int N;
    int tmp;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%d", &tmp);
        pq.push(tmp);
    }

    if (N == 1)
    {
        cout << 0;
    }
    else
    {
        long long ans = 0;

        while (true)
        {
            if (pq.size() == 1)
                break;
            int fi = pq.top();
            pq.pop();
            int se = pq.top();
            pq.pop();

            ans += (fi + se);
            pq.push(fi + se);
        }

        printf("%lld", ans);
    }
    return 0;
}