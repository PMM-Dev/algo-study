//freopen("input.txt", "r", stdin);
//2052kb 24ms
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

int N;
int arr[101][101];
int checkarea[101][101] = {
    0,
};
bool area[101][101];
int adx[4] = {1, -1, 0, 0};
int ady[4] = {0, 0, 1, -1};

void dfs(int i, int j, int idx)
{
    if (checkarea[i][j] > 0)
        return;

    checkarea[i][j] = idx;
    for (int p = 0; p < 4; p++)
    {
        int nx = j + adx[p];
        int ny = i + ady[p];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (checkarea[ny][nx] > 0 || area[ny][nx] == false)
            continue;

        dfs(ny, nx, idx);
    }
}

int dfsstart()
{
    int idx = 0;
    fill(checkarea[0], checkarea[0] + 101 * 101, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (area[i][j] == true)
            {
                if (checkarea[i][j] == 0)
                    idx++;
                dfs(i, j, idx);
            }
        }
    }
    return idx;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int ans = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int h = 0; h < 101; h++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] <= h)
                    area[i][j] = false;
                else
                    area[i][j] = true;
            }
        }

        ans = max(ans, dfsstart());
    }

    cout << ans;
}
