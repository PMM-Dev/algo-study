//freopen("input.txt", "r", stdin);
//6636kb 48ms
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

void solve()
{
    string S;
    string Sp;

    cin >> S;

    for (int i = 0; i < S.size(); i++)
    {

        if (i == 0)
        {
            int tmp = S[i] - '0';
            while (tmp--)
            {
                Sp.push_back('(');
            }
        }

        if (i == S.size() - 1)
        {
            Sp.push_back(S[S.size() - 1]);
            int tmp = S[S.size() - 1] - '0';
            while (tmp--)
            {
                Sp.push_back(')');
            }
            break;
        }

        Sp.push_back(S[i]);

        if (S[i + 1] > S[i])
        {
            int tmp = S[i + 1] - S[i];
            while (tmp--)
            {
                Sp.push_back('(');
            }
        }
        else if (S[i + 1] < S[i])
        {
            int tmp = S[i] - S[i + 1];
            while (tmp--)
            {
                Sp.push_back(')');
            }
        }
    }

    cout << Sp << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;
    int i = 1;

    while (T--)
    {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }

    return 0;
}