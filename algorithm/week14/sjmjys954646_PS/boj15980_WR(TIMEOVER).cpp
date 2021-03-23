//freopen("input.txt", "r", stdin);
//2028kb 4ms
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
#include <stdlib.h>

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

int M, N;
vector<pair<char, string>> birds;
int selectedidx;
int finalinterruptionMAX = INF;
int interruptionMAX;
int interruption = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.F == b.F)
    {
        return a.S < b.S;
    }
    else
    {
        return a.F < b.F;
    }
}

void simulation()
{
    interruption = 0;
    interruptionMAX = -INF;
    for (int t = 0; t < M; t++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == selectedidx)
                continue;

            if (birds[i].S[t] == '0')
                continue;

            if (birds[i].F == 'L')
            {
                interruption--;
            }
            else
            {
                interruption++;
            }
        }
        interruptionMAX = max(interruptionMAX, abs(interruption));
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    vector<pair<int, int>> ansbird;

    scanf("%d %d", &N, &M);

    rep(i, N)
    {
        string tmp;
        char direction;
        cin >> direction >> tmp;
        birds.push_back({direction, tmp});
    }

    rep(i, N)
    {
        selectedidx = i;
        simulation();
        ansbird.push_back({interruptionMAX, i + 1});
    }
    sort(ansbird.begin(), ansbird.end(), compare);
    rep(i, ansbird.size())
    {
        cout << ansbird[i].F << " " << ansbird[i].S << "\n";
    }
    printf("%d\n%d", ansbird.front().S, ansbird.front().F);

    return 0;
}