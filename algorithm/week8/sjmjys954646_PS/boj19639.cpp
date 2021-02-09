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

priority_queue<pii> person;
priority_queue<pii> item;
int X, Y, M;

int main()
{
    int tmp;
    bool check = true;
    vector<int> ans;

    scanf("%d %d %d", &X, &Y, &M);

    int curM = M;

    rep(i, X)
    {
        scanf("%d", &tmp);
        person.push({tmp, i + 1});
    }

    rep(i, Y)
    {
        scanf("%d", &tmp);
        item.push({tmp, i + 1});
    }

    while (true)
    {
        if (person.empty())
            break;

        int cur = person.top().F;
        int curindex = person.top().S;
        person.pop();

        if (curM <= M / 2)
        {
            while (true)
            {
                if (curM > M / 2)
                    break;

                if (item.empty())
                {
                    break;
                }

                int itemcur = item.top().F;
                int itemindex = item.top().S;
                curM += itemcur;
                item.pop();
                ans.push_back(itemindex);
            }
            curM -= cur;
            ans.push_back(-curindex);
            if (curM <= 0)
            {
                check = false;
                break;
            }
        }
        else
        {
            curM -= cur;
            ans.push_back(-curindex);
        }
    }

    while (!item.empty())
    {
        int itemindex = item.top().S;
        item.pop();
        ans.push_back(itemindex);
    }

    if (check)
    {
        rep(i, ans.size())
        {
            printf("%d\n", ans[i]);
        }
    }
    else
    {
        printf("0");
    }

    return 0;
}
