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

vi vowel;
vi consonent;
vi vowelCheck = {0, 4, 8, 14, 20};
vi finalPerm;
vi selected;
map<vi, int> m;
int cnt = 0;
int L, C;

void Perm(int index)
{
    if (selected.size() == L)
    {
        vi tmpvec = selected;
        sort(selected.begin(), selected.end());
        // cout << cnt << ":";
        // rep(i, L)
        // {
        //     cout << selected[i] << " ";
        // }
        // cout << "\n";
        m[selected] = ++cnt;
        selected = tmpvec;
        return;
    }

    for (int i = index; i < finalPerm.size(); i++)
    {
        selected.push_back(finalPerm[i]);
        Perm(i + 1);
        selected.pop_back();
    }
}

void makefinalPerm()
{
    finalPerm.clear();
    rep(i, vowel.size())
    {
        if (find(selected.begin(), selected.end(), vowel[i]) != selected.end())
            continue;
        finalPerm.push_back(vowel[i]);
    }
    rep(i, consonent.size())
    {
        if (find(selected.begin(), selected.end(), consonent[i]) != selected.end())
            continue;
        finalPerm.push_back(consonent[i]);
    }
    sort(finalPerm.begin(), finalPerm.end());
    return;
}

void consonentSelect(int index, int K)
{
    if (K == 2)
    {
        makefinalPerm();
        Perm(0);
        return;
    }

    for (int i = index; i < consonent.size(); i++)
    {
        selected.push_back(consonent[i]);
        consonentSelect(i + 1, K + 1);
        selected.pop_back();
    }
}

void vowelSelect()
{
    rep(i, vowel.size())
    {
        selected.push_back(vowel[i]);
        consonentSelect(0, 0);
        selected.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    char tmp;

    scanf("%d %d", &L, &C);

    while (true)
    {
        scanf("%c", &tmp);
        if ((int)'a' > (int)tmp || (int)'z' < (int)tmp)
            continue;
        tmp -= (int)'a';
        if (find(vowelCheck.begin(), vowelCheck.end(), tmp) != vowelCheck.end())
            vowel.push_back(tmp);
        else
            consonent.push_back(tmp);

        if ((vowel.size() + consonent.size()) == C)
            break;
    }

    sort(vowel.begin(), vowel.end());
    sort(consonent.begin(), consonent.end());

    vowelSelect();

    for (auto i = m.begin(); i != m.end(); i++)
    {
        vi vecout = i->first;
        rep(i, vecout.size())
        {
            printf("%c", vecout[i] + 'a');
        }
        printf("\n");
    }

    return 0;
}