//freopen("input.txt", "r", stdin);
//2288kb 12ms
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
/*통상적으로 나누는 방법은 무조건 시간초과가 날것이라는 사실을 알고 있었지만
파라메트릭 서치까지 생각은 했지만 구간별로 나누면서 어떻게 구현해야될지 몰라서 답지봄*/
//https://github.com/kks227/BOJ/blob/master/17900/17951.cpp

int main()
{
    freopen("input.txt", "r", stdin);

    int N, K;
    int lo = 0;
    int hi = 1;
    int arr[100002];

    scanf("%d %d", &N, &K);

    rep(i, N)
    {
        scanf("%d", &arr[i]);
        hi += arr[i];
    }

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            if (sum >= mid)
            {
                sum = 0;
                cnt++;
            }
        }
        (cnt >= K ? lo : hi) = mid;
    }
    printf("%d\n", lo);

    return 0;
}