//freopen("input.txt", "r", stdin);
//2148kb 0ms
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

using namespace std;

vector<ll> arr;
int N;

int main()
{
    freopen("input.txt", "r", stdin);

    ll sum = 0;
    ll budget;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%lld", &budget);
        arr.push_back(budget);
        sum += budget;
    }
    scanf("%lld", &budget);
    sort(arr.begin(), arr.end());

    int idx = 0;
    ll tmp;
    ll res;
    if (budget >= sum)
    {
        printf("%lld", arr[N - 1]);
    }
    else
    {
        while (true)
        {
            tmp = budget;
            tmp /= (N - idx);
            auto it = lower_bound(arr.begin() + idx, arr.end(), tmp);
            if (it == arr.begin() + idx)
            {
                res = tmp;
                break;
            }
            else
            {
                budget -= arr[idx];
                idx++;
            }
        }
        printf("%lld", res);
    }

    return 0;
}
