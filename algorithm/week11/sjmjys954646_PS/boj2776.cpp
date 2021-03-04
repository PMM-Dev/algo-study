//freopen("input.txt", "r", stdin);
//9832kb 780ms
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

int main()
{
    freopen("input.txt", "r", stdin);

    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        vi tsutseup1;
        vi tsutseup2;
        int tmp;
        int tsusize;

        scanf("%d", &tsusize);

        tsutseup1.resize(tsusize);

        rep(i, tsusize)
        {
            scanf("%d", &tsutseup1[i]);
        }

        scanf("%d", &tsusize);

        tsutseup2.resize(tsusize);

        rep(i, tsusize)
        {
            scanf("%d", &tsutseup2[i]);
        }

        sort(tsutseup1.begin(), tsutseup1.end());

        rep(i, tsusize)
        {
            auto it = binary_search(tsutseup1.begin(), tsutseup1.end(), tsutseup2[i]);
            if (it)
                printf("1\n");
            else
                printf("0\n");
        }
    }

    return 0;
}