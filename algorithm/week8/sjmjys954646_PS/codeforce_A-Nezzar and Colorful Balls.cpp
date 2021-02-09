//kb 15ms
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

int arr[102];
int select[102];

int main()
{
    freopen("input.txt", "r", stdin);
    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        memset(arr, 0, sizeof(arr));
        memset(select, 0, sizeof(select));
        int N;
        int ans = 0;
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        int l = 0;
        int t = 0;
        while (t < N)
        {
            int m = -1;
            for (int i = 0; i <= N; i++)
            {
                if (i == N)
                {
                    ans++;
                    break;
                }

                if (m < arr[i] && select[i] == 0)
                {
                    select[i] = 1;
                    m = arr[i];
                    t++;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
