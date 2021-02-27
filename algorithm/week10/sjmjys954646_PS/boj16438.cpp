//6132kb 84ms
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

int N;
vector<int> result[7];

void day(vi v, int start, int end, int depth)
{
    if (depth == 7)
        return;

    int mid = (start + end) / 2;

    for (int i = mid; i < end; i++)
    {
        v[i] = -v[i];
    }

    for (int i = start; i < end; i++)
    {
        result[depth].push_back(v[i]);
    }

    day(v, start, mid, depth + 1);
    day(v, mid, end, depth + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    vi v(N, 1);

    day(v, 0, N, 0);

    for (int i = 0; i < 7; i++)
    {
        for (auto it : result[i])
        {
            if (it == 1)
                printf("A");
            else
                printf("B");
        }
        printf("\n");
    }

    return 0;
}
