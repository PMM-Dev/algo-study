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
    int N;
    int A1 = 0;
    int A2 = 0;
    int A3 = 0;
    int tmp;

    cin >> N;

    vector<vector<int>> arr(N);

    for (int i = 0; i < N; i++)
    {
        arr[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (i == j)
            {
                A1 += arr[i][j];
            }
        }

        for (int j = 0; j < N; j++)
        {
            tmp = arr[i][j];
            int cnt = count(arr[i].begin(), arr[i].end(), tmp);
            if (cnt != 1)
            {
                A2++;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        bool A3check = false;
        for (int j = 0; j < N; j++)
        {
            tmp = arr[j][i];
            for (int k = 0; k < N; k++)
            {
                if (k == j)
                    continue;
                if (tmp == arr[k][i])
                {
                    A3check = true;
                    break;
                }
            }
        }
        if (A3check)
            A3 += 1;
    }
    cout << A1 << " " << A2 << " " << A3 << "\n";
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